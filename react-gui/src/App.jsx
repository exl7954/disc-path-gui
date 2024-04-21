import React, { useState, useEffect, useRef } from "react";
import { CanvasProvider } from "./components/CanvasProvider";
import InputForm from "./components/InputForm";
import { generateBox, generatePolygon, readPolygon } from "./components/methods";
import "./App.css";
import Disc from "./components/Disc";
import Path from "./components/Path";
import FileProcessor from "./components/FileProcessor";
import OutputStats from "./components/OutputStats";



function App() {
  // connect to ROS
  const [connection, setConnection] = useState("closed");
  const [rosRequest, setRosRequest] = useState({});
  const [drawObj, setDrawObj] = useState({});
  const [working, setWorking] = useState(false); // true if waiting for response from ROS
  const [response, setResponse] = useState({}); // response from ROS
  const [externalChange, setExternalChange] = useState({}); // request object when imported from file

  useEffect(() => {
    if (working) {
      let ros = new ROSLIB.Ros({
        url: "ws://localhost:9090",
      });
      ros.on('connection', function () {
        console.log('Connected to websocket server.');
        setConnection("open");
      });
      ros.on('error', function (error) {
        console.log('Error connecting to websocket server: ', error);
        setConnection("error");
        setWorking(false);
      });
      ros.on('close', function () {
        console.log('Connection to websocket server closed.');
      });

      let client = new ROSLIB.Service({
        ros: ros,
        name: '/find_path',
        serviceType: 'interfaces/srv/FindPath'
      });
      console.log("in effect");
      let request = new ROSLIB.ServiceRequest(rosRequest);
      client.callService(request, function (result) {
        console.log('Result for service call on ' + client.name + ': ' + JSON.stringify(result));
        setResponse(result);
        setWorking(false);
        setConnection("closed");
        ros.close();
      });
    }
  }, [working])
  const options = [
    'one', 'two', 'three'
  ];
  const defaultOption = options[0];
  

  const containerRef = useRef(null);
  return (
    <>
      <InputForm rosRequest={rosRequest} setRosRequest={setRosRequest} 
                working={working} setWorking={setWorking} 
                setResponse={setResponse} 
                externalChange={externalChange} setExternalChange={setExternalChange} />
      <FileProcessor rosRequest={rosRequest} setRosRequest={setRosRequest} setExternalChange={setExternalChange} />
      <div className="container" id="container" ref={containerRef}>
        <CanvasProvider width={rosRequest.boxwidth || 512} height={rosRequest.boxheight || 512} Request={rosRequest} setDrawObj={setDrawObj}>
          <Disc x={drawObj.alpha ? drawObj.alpha[0] : drawObj.alphax} y={drawObj.alpha ? drawObj.alpha[1] : drawObj.alphay} r={drawObj.r0} color={"#C4E4FF"} />
          <Disc x={drawObj.bta ? drawObj.bta[0] : drawObj.betax} y={drawObj.bta ? drawObj.bta[1] : drawObj.betay} r={drawObj.r0} color={"pink"} />
          <Path response={response} />
          {generatePolygon(readPolygon(drawObj))}
          {response.boxes ? generateBox(response.boxes) : null}
        </CanvasProvider>
        
        <OutputStats rosRequest={rosRequest} response={response} containerRef={containerRef} />
      </div>
      
    </>
  )
};

export default App;