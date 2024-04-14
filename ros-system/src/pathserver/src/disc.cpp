/* **************************************
   File: disc.cpp

   Description: 
	This is the entry point for the running the SSS algorithm
	for a disc robot amidst a collection of polygonal obstacles.

	To run, call with these positional arguments:

	> ./disc 	[interactive = 0] \
			[alpha-x = 10] [alpha-y = 360] \
			[beta-x = 500] [beta-y = 20] \
			[epsilon = 1] \
			[R0 = 30] \
			[fileName = input2.txt] \
			[boxWidth = 512] [boxHeight = 512] \
			[windoxPosX = 400] [windowPosY = 200] \
			[Qtype = 0] [seed = 111] [inputDir = inputs] \
			[deltaX = 0] [deltaY = 0] [scale = 1] \

	where 
		interactive 	 	is nature of run
	       					(0=interactive, >0 is non-interactive)
		alpha			is start configuration
		beta			is goal configuration
		epsilon			is resolution parameter
		R0			is robot radius
		fileName		is input file describing the environment
		box Width/Height	is initial box dimensions
		windowPos		is position of window
		Qtype			is type of the priority queue
						(sequential=0, random=1)
		seed			is seed for random number generator
		inputDir		is directory for input files
		deltaX, deltaY, scale	is translation and scaling of input environment

	NOTE: see several examples of running this program in the Makefile.
	
	Format of input environment: see README FILE

   HISTORY: March, 2012: Cong Wang, Chee Yap and Yi-Jen Chiang

   Since Core Library  Version 2.1
   $Id: disc.cpp,v 1.1 2012/10/26 03:58:52 cheeyap Exp cheeyap $
 ************************************** */

#include "QuadTree.h"
#include "PriorityQueue.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.h"
#include "Timer.h"
#include "Box.h"
#include <queue>

#include "rclcpp/rclcpp.hpp"
#include "interfaces/srv/test_service.hpp"
#include "interfaces/srv/find_path.hpp"

#include <set>
//#include "CoreIo.h"

using namespace std;

QuadTree* QT;

// GLOBAL INPUT Parameters ========================================
//
	double alpha[2] = {10, 360};		// start configuration
	double bta[2] = {500, 20};		// goal configuration
	double epsilon = 1;			// resolution parameter
	Box* boxA;				// start box (containing alpha)
	Box* boxB;				// goal box (containing beta)
	double boxWidth = 512;			// Initial box width
	double boxHeight = 512;			// Initial box height
	double R0 = 30;				// Robot radius 
	int windowPosX = 400;			// X Position of Window
	int windowPosY = 200;			// Y Position of Window

	int QType = 0;				// The Priority Queue can be
						//    sequential (0) or random (1)
	int interactive = 0;			// Run interactively?
						//    Yes (0) or No (1)
	int seed = 111;				// seed for random number generator
						// (Could also be used for BFS, etc)
	double deltaX=0;			// x-translation of input environment
	double deltaY=0;			// y-translation of input environment
	double scale=1;				// scaling of input environment

	bool noPath = true;			// True means there is "No path.
 
	bool hideBoxBoundary = false;  //don't draw box boundary

	int freeCount = 0;
	int stuckCount = 0;
	int mixCount = 0;
	int mixSmallCount = 0;

void parseFromInput(Box*, int, string, int, string, double, double, double);
void treeTraverse(Box*, stringstream&);

// THIS IS JUST FOR THE GreedyBestFirst Heuristic!
//    -- should be completely general!
//find path using simple heuristic:
//use distance to beta as key in PQ, see dijkstraQueue
bool findPath(Box* a, Box* b, QuadTree* QT, int& ct)
{
	bool isPath = false;
	vector<Box*> toReset;
	a->dist2Source = 0;
	dijkstraQueue dijQ;
	dijQ.push(a);
	toReset.push_back(a);
	while(!dijQ.empty())
	{
		Box* current = dijQ.extract();
		current->visited = true;

		// if current is MIXED, try expand it and push the children that is
		// ACTUALLY neighbors of the source set (set containing alpha) into the dijQ again
		if (current->status == Box::MIXED)
		{
			if (QT->expand(current))
			{
				++ct;
				for (int i = 0; i < 4; ++i)
				{
					// go through neighbors of each child to see if it's in source set
					// if yes, this child go into the dijQ
					bool isNeighborOfSourceSet = false;
					for (int j = 0; j < 4 && !isNeighborOfSourceSet; ++j)
					{
						BoxIter* iter = new BoxIter(current->pChildren[i], j);
						Box* n = iter->First();
						while (n && n != iter->End())
						{
							if (n->dist2Source == 0)
							{
								isNeighborOfSourceSet = true;
								break;
							}
							n = iter->Next();
						}							
					}					
					if (isNeighborOfSourceSet)
					{

						switch (current->pChildren[i]->getStatus())
						{
							//if it's FREE, also insert to source set
							case Box::FREE:
								current->pChildren[i]->dist2Source = 0;
								dijQ.push(current->pChildren[i]);
								toReset.push_back(current->pChildren[i]);
								break;
							case Box::MIXED:
								dijQ.push(current->pChildren[i]);
								toReset.push_back(current->pChildren[i]);
								break;
							case Box::STUCK:
								cerr << "inside FindPath: STUCK case not treated" << endl;
								break;
							case Box::UNKNOWN:
								cerr << "inside FindPath: UNKNOWN case not treated" << endl;
						}
					}
				}
			}
			continue;
		}

		//found path!
		if (current == b)
		{			
			isPath = true;
			break;
		}

		// if current is not MIXED, then must be FREE
		// go through it's neighbors and add FREE and MIXED ones to dijQ
		// also add FREE ones to source set 
		for (int i = 0; i < 4; ++i)
		{
			BoxIter* iter = new BoxIter(current, i);
			Box* neighbor = iter->First();
			while (neighbor && neighbor != iter->End())
			{
				if (!neighbor->visited && neighbor->dist2Source == -1 && (neighbor->status == Box::FREE || neighbor->status == Box::MIXED))
				{					
					if (neighbor->status == Box::FREE)
					{
						neighbor->dist2Source = 0;
					}						
					dijQ.push(neighbor);	
					toReset.push_back(neighbor);
				}
				neighbor = iter->Next();
			}
		}
	}

	//these two fields are also used in dijkstraShortestPath
	// need to reset
	for (int i = 0; i < (int)toReset.size(); ++i)
	{
		toReset[i]->visited = false;
		toReset[i]->dist2Source = -1;
	}

	return isPath;
}

// SAMPLE TEST SERVICE ========================================
void add(const std::shared_ptr<interfaces::srv::TestService::Request> request,     
          std::shared_ptr<interfaces::srv::TestService::Response>       response)  
{
  response->sum = request->a + request->b;                                      
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",  
                request->a, request->b);                                         
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}
// ============================================================

void service_run(const std::shared_ptr<interfaces::srv::FindPath::Request> request, std::shared_ptr<interfaces::srv::FindPath::Response> response)
{
	/* REQUEST FORMAT
	float64[2] alpha [10, 360]
	float64[2] bta [500, 20]
	float64 epsilon 1
	float64 boxwidth 512
	float64 boxheight 512
	float64 r0 30
	int64 qtype 0
	int64 seed 111
	float64 deltax 0
	float64 deltay 0
	float64 scale 1
	int64 numpts 12
	string pts "10,502|110,502|110,402|10,402|200,312|250,332|300,292|210,162|220,202|50,112|100,162|150,92"
	int64 numpolygons 3
	string polygons "1,4,3,2,1|5,9,8,7,6,5|10,12,11,10"
	---
	string response
	string path
	string boxes
	*/
	// SET VARIABLES
	alpha[0] = request->alpha[0];
	alpha[1] = request->alpha[1];
	bta[0] = request->bta[0];
	bta[1] = request->bta[1];
	epsilon = request->epsilon;
	boxWidth = request->boxwidth;
	boxHeight = request->boxheight;
	R0 = request->r0;
	QType = request->qtype;
	seed = request->seed;
	deltaX = request->deltax;
	deltaY = request->deltay;
	scale = request->scale;

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Received request.");
	cout << request->pts << endl;
	cout << request->polygons << endl;

	Timer t;
	t.start();

	// gen empty tree
	Box* root = new Box(request->boxwidth/2, request->boxheight/2, request->boxwidth, request->boxheight);
	Box::r0 = request->r0;
	parseFromInput(root, request->numpts, request->pts, request->numpolygons, request->polygons, request->deltax, request->deltay, request->scale);
	root->updateStatus();
	if (QT)
	{
		delete(QT);
	}
	QT = new QuadTree(root, request->epsilon, request->qtype, request->seed);  // Note that seed keeps changing!

	// ******************** START ALGORITHM ****************************************************
	noPath = false;	// Confusing use of "noPath"
	int ct = 0;
	freeCount = 0;
	stuckCount = 0;
	mixCount = 0;
	mixSmallCount = 0;

	if (request->qtype == 0 || request->qtype == 1) // 0=random, 1=BFS
	{
		boxA = QT->getBox(request->alpha[0], request->alpha[1]);
		cout<<"!boxA->isFree()="<<(!boxA->isFree())<<endl;
		while (boxA && !boxA->isFree())
		{	
			if (!QT->expand(boxA))
			{
				noPath = true; // Confusing use of "noPath"
				break;
			}
			++ct;
			boxA = QT->getBox(boxA, request->alpha[0], request->alpha[1]);
		}

		boxB = QT->getBox(request->bta[0], request->bta[1]);
		cout<<"!boxB->isFree()="<<(!boxB->isFree())<<endl;
		while (!noPath && boxB && !boxB->isFree())
		{
			if (!QT->expand(boxB))
			{
				noPath = true;
				break;
			}
			++ct;
			boxB = QT->getBox(boxB, request->bta[0], request->bta[1]);
		}
		// similar to findPath (for QType 2) -- so it is a duplicated logic
		while(!noPath && !QT->isConnect(boxA, boxB)) {
			if (!QT->expand()) // should ct be passed to expand?
			{
				noPath = true;
			}
			++ct;
		}
	} 
	else if(QType == 2)
	{
		boxA = QT->getBox(request->alpha[0], request->alpha[1]);
		// split until the box containing A is free (or, NOPATH)
		while (boxA && !boxA->isFree())
		{
			if (!QT->expand(boxA))
			{
				noPath = true;
				break;
			}
			boxA = QT->getBox(boxA, request->alpha[0], request->alpha[1]);
		}

		boxB = QT->getBox(request->bta[0], request->bta[1]);
		// split until the box containing B is free (or, NOPATH)
		while (!noPath && boxB && !boxB->isFree())
		{
			if (!QT->expand(boxB))
			{
				noPath = true;
				break;
			}
			boxB = QT->getBox(boxB, request->bta[0], request->bta[1]);
		}

		// findPath will split until exists path from boxA to boxB (or, NOPATH)
		noPath = !findPath(boxA, boxB, QT, ct);
	}	

	// stop timer
	t.stop();

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Path found? %s", !noPath ? "true" : "false");
	cout << ">>     Time used: " << t.getElapsedTimeInMilliSec() << " ms\n";
	response->response = !noPath ? "true" : "false";
	cout << ">>>>>>>>>>>>>>> > > > > > > >>>>>>>>>>>>>>>>>>\n";
	cout << "Expanded " << ct << " times" << endl;
	cout << "total Free boxes: " << freeCount << endl;
	cout << "total Stuck boxes: " << stuckCount << endl;
	cout << "Epsilon: " <<epsilon << endl;
	cout << "total Mixed boxes smaller than epsilon: " << mixSmallCount << endl;
	cout << "total Mixed boxes bigger than epsilon: " << mixCount - ct - mixSmallCount << endl;

	if (!noPath) {
		// return path points
		stringstream responsePath;
		vector<Box*> path = Graph::dijketraShortestPath(boxA, boxB);
		cout << "Path length: " << path.size() << endl;
		cout << "Path: ";
		for (int i = 0; i < (int)path.size(); ++i)
		{
			cout << path[i]->x << " " << path[i]->y << " | ";
			responsePath << path[i]->x << " " << path[i]->y << " | ";
		}
		cout << endl;
		response->path = responsePath.str();
	}
	// return boxes
	stringstream responseBoxes;
	treeTraverse(QT->pRoot, responseBoxes);
	response->boxes = responseBoxes.str();

	// return stats
	response->elapsedtime = t.getElapsedTimeInMilliSec();
	response->expandcount = ct;
	response->totalfree = freeCount;
	response->totalstuck = stuckCount;
	response->mixsmaller = mixSmallCount;
	response->mixbigger = mixCount - ct - mixSmallCount;
}

// MAIN PROGRAM: ========================================
int main(int argc, char* argv[])
{
	// Initialize ROS
	rclcpp::init(argc, argv);
	// Create service node
	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("test_server");

	// Add service to node
	rclcpp::Service<interfaces::srv::FindPath>::SharedPtr service = node->create_service<interfaces::srv::FindPath>("find_path",  &service_run);
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready.");
	rclcpp::spin(node);
  	rclcpp::shutdown();
	
	return 0;
}

void treeTraverse(Box* b, stringstream& responseStr)
{	
	if (!b)
	{
		return;
	}
	if (b->isLeaf)
	{
		// x,y!width,height!status|
		responseStr << b->x << "," << b->y << "!" << b->width << "," << b->height << "!" << b->status << "|";
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		treeTraverse(b->pChildren[i], responseStr);
	}
}

/* TOOLS FOR DRAWING GLUI ======================================== NO LONGER NEEDED
void drawPath(vector<Box*>& path)
{
	glColor3f(0.5, 0, 0.25);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);	
	glVertex2f(beta[0], beta[1]);
	for (int i = 0; i < (int)path.size(); ++i)
	{
		glVertex2f(path[i]->x, path[i]->y);	
	}
	glVertex2f(alpha[0], alpha[1]);
	glEnd();
	glLineWidth(1.0);
}

void drawQuad(Box* b)
{
	switch(b->status)
	{
	case Box::FREE:
		glColor3f(0.25, 1, 0.25);
		break;
	case Box::STUCK:
		glColor3f(1, 0.25, 0.25);
		break;
	case Box::MIXED:
		glColor3f(1, 1, 0.25);
		if (b->height < epsilon || b->width < epsilon)
		{
			glColor3f(0.5, 0.5, 0.5);
		}
		break;
	case Box::UNKNOWN:
		std::cout << "UNKNOWN in drawQuad" << std::endl;
	}
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glVertex2f(b->x - b->width / 2, b->y - b->height / 2);
	glVertex2f(b->x + b->width / 2, b->y - b->height / 2);
	glVertex2f(b->x + b->width / 2, b->y + b->height / 2);
	glVertex2f(b->x - b->width / 2, b->y + b->height / 2);
	glEnd();

	if (!hideBoxBoundary)
	{
		glColor3f(0, 0 , 0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_POLYGON);
		glVertex2f(b->x - b->width / 2, b->y - b->height / 2);
		glVertex2f(b->x + b->width / 2, b->y - b->height / 2);
		glVertex2f(b->x + b->width / 2, b->y + b->height / 2);
		glVertex2f(b->x - b->width / 2, b->y + b->height / 2);
		glEnd();
	}	
}

void drawWalls(Box* b)
{
	glColor3f(1, 1, 1);
	glLineWidth(2.0);
	for (list<Wall*>::iterator iter = b->walls.begin(); iter != b->walls.end(); ++iter)
	{
		Wall* w = *iter;
		glBegin(GL_LINES);
		glVertex2f(w->src->x, w->src->y);
		glVertex2f(w->dst->x, w->dst->y);
		glEnd();
	}
	glLineWidth(1.0);
}



void drawCircle( float Radius, int numPoints, double x, double y, double r, double g, double b)
{	
	glColor3d(r,g,b);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	
	glBegin(GL_POLYGON);
	for( int i = 0; i <= numPoints; ++i )
	{
		float Angle = i * (2.0* 3.1415926 / numPoints);  
		float X = cos( Angle )*Radius;  
		float Y = sin( Angle )*Radius;
		glVertex2f( X + x, Y + y);
	}
	glEnd();
}

void filledCircle( double radius, double x, double y, double r, double g, double b) 
{
	int numPoints = 100;
	glColor3d(r,g,b);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	for( int i = 0; i <= numPoints; ++i )
	{
		float Angle = i * (2.0* 3.1415926 / numPoints);  
		float X = cos( Angle )*radius;  
		float Y = sin( Angle )*radius;
		glVertex2f( X + x, Y + y);
	}
	glEnd();
}

void drawLine()
{
	if (noPath)
	{
		glColor3f(0, 0, 0);
	} 
	else
	{
		glColor3f(1, 0, 0);
	}
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glVertex2f(alpha[0], alpha[1]);
	glVertex2f(beta[0], beta[1]);
	glEnd();
	glLineWidth(1.0);
}


void renderScene(void) 
{
	hideBoxBoundary = radioDrawOption->get_int_val();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glScalef(2.0/boxWidth, 2.0/boxHeight, 0);
	glTranslatef(-boxWidth/2, -boxHeight/2, 0);

	treeTraverse(QT->pRoot);

	glPolygonMode(GL_FRONT, GL_LINE);

	drawCircle(R0, 100, alpha[0], alpha[1], 0, 0, 1);	// start
	drawCircle(R0, 100, beta[0], beta[1], 0, 0, 1);		// goal

	double r0 = 5;
	if (r0>R0) r0=R0;
	filledCircle(r0, alpha[0], alpha[1], 0.2, 0.2, 1.0);	//blue start center
	filledCircle(r0, beta[0], beta[1], 0.4, 0.4, 0.1);	//yellow goal center

	drawWalls(QT->pRoot);

	drawLine();

	if (!noPath)
	{
		vector<Box*> path = Graph::dijketraShortestPath(boxA, boxB);
		drawPath(path);
	}

	glutSwapBuffers();
}
*/

/* ********************************************************************** */
void parseFromInput(Box* b, int nPt, string points, int nPolygons, string polygons, double deltaX, double deltaY, double scale) {
	/* REQUEST FORMAT
	int64 numpts 12
	string pts "10,502|110,502|110,402|10,402|200,312|250,332|300,292|210,162|220,202|50,112|100,162|150,92"
	int64 numpolygons 3
	string polygons "1,4,3,2,1|5,9,8,7,6,5|10,12,11,10"
	---
	string response
	*/

	// populate pts array from string using same logic as parseConfigFile
	vector<double> pts(nPt*2);
	string currNum = "";
	int counter = 0;
	for (int i = 0; i < (int)points.size(); i++) {
		if (points[i] == '|' || points[i] == ',' || i == (int)points.size() - 1) {
			if (i == (int)points.size() - 1) {currNum += points[i];} // if last char, add to number
			pts[counter] = stod(currNum);
			currNum = "";
			counter++;
		} else {
			currNum += points[i];
		}
	}
	// DEBUG:
	// print pts vector
	for (double i: pts) {
		cout << i << " ";
	}


	// modify Box b from string using same logic as parseConfigFile
	for (int i = 0; i < nPolygons; ++i)
	{

		queue<int> q;
		string currNum = "";
		for (int j = 0; j < (int)polygons.size(); j++) {
			if (polygons[j] == '|' || j == (int)polygons.size() - 1) {
				if (j == (int)polygons.size() - 1) {currNum += polygons[j];} // if last char, add to number
				q.push(stoi(currNum));
				break;
			}
			if (polygons[j] == ',') {
				q.push(stoi(currNum));
				currNum = "";
			} else {
				currNum += polygons[j];
			}
		}

		// delete first polygon from string after finding it
		if (i != nPolygons - 1) {
			polygons = polygons.substr(polygons.find('|') + 1);
		}

		vector<Corner*> ptVec;
		set<int> ptSet;
		while (!q.empty())
		{
			int pt;
			/// TODO:
			pt = q.front();
			q.pop();
			pt -= 1; //1 based array
			if (ptSet.find(pt) == ptSet.end())
			{
				ptVec.push_back(new Corner(pts[pt*2]*scale+deltaX,
					    	pts[pt*2+1]*scale+deltaY));


				b->addCorner(ptVec.back());
				ptSet.insert(pt);
				if (ptVec.size() > 1)
				{
					Wall* w = new Wall(ptVec[ptVec.size()-2], ptVec[ptVec.size()-1]);
					b->addWall(w);
				}				
			}
			//new pt already appeared, a loop is formed. should only happen on first and last pt
			else
			{
				if (ptVec.size() > 1)
				{
					Wall* w = new Wall(ptVec[ptVec.size()-1], ptVec[0]);
					b->addWall(w);
					break;
				}	
			}
		}
	}
}
