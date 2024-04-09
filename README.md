### Steps to Run Server

These steps assume that you have ROS Humble correctly installed and sourced. If unsure, please follow this [tutorial](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Configuring-ROS2-Environment.html).

1. Download or clone the repository.
2. Run `colcon build` in `ros-system` to compile.
3. Run `source install/setup.bash` in `ros-system` to source the newly compiled packages.
4. Install ROSBridge using `sudo apt-get install ros-humble-rosbridge-server`.
5. After installing ROSBridge, re-source ROS using `source /opt/ros/humble/setup.bash`.
6. Run `ros2 run pathserver server` to start a service node on the ROS network.
7. In a new terminal window, repeat step 3, then run `ros2 launch rosbridge_server rosbridge_websocket_launch.xml` to open a WebSocket listening on port 9090. 
8. Test the connection by opening `ros-system/src/pathserver/src/test.html` with your browser. This file contains a script that calls the service with default arguments.
9. Download node.js on the internet. At "https://nodejs.org/en/download",select the correct version and platform and download the installer. Install the node.js
10. Run `npm install` in `react-gui` to install dependencies.
11. Run `npm run dev` in `react-gui` start the React project, and the port of the website will show up in the terminal.n

Feel free to send me an email or open an [Issue](https://github.com/exl7954/disc-path-gui/issues) in this repository if you have trouble running the server.

