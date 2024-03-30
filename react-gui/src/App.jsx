import React, { useState } from "react";
import { CanvasProvider } from "./components/CanvasProvider";
import Rectangle from "./components/Rectangle";
import Polygon from "./components/Polygon";
import Path from "./components/Path";
import { RosProcessor } from "./components/RosProcessor";
import { generateBox, generatePolygon, processessOutPut } from "./components/methods";
import { FileUploader } from "./components/FileUploader";
import InputForm from "./components/InputForm";
import "./App.css";

function App() {
  // connect to ROS
  const [connection, setConnection] = useState("closed");
  const [rosRequest, setRosRequest] = useState({});
  /*
  var ros = new ROSLIB.Ros({
    url: 'ws://localhost:9090'
  });
  ros.on('connection', function() {
      console.log('Connected to websocket server.');
      setConnection("open");
  });
  ros.on('error', function(error) {
      console.log('Error connecting to websocket server: ', error);
      setConnection("error");
  });
  ros.on('close', function() {
      console.log('Connection to websocket server closed.');
      setConnection("closed");
  });

  var client = new ROSLIB.Service({
      ros: ros,
      name: '/find_path',
      serviceType: 'interfaces/srv/FindPath'
  });
  */

  return (
    <>
      <p>Connection Status: {connection}</p>
      <InputForm rosRequest={rosRequest} setRosRequest={setRosRequest} />
      <p>ROS Request: {JSON.stringify(rosRequest)}</p>
    </>
  )
};

export default App;