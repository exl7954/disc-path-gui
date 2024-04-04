import React, { useState, useEffect } from "react";
import { CanvasProvider } from "./components/CanvasProvider";
import InputForm from "./components/InputForm";
import "./App.css";
import Disc from "./components/Disc";



function App() {
  // connect to ROS
  const [connection, setConnection] = useState("closed");
  const [rosRequest, setRosRequest] = useState({});
  const [drawObj, setDrawObj] = useState({});
  const [working, setWorking] = useState(false); // true if waiting for response from ROS
  const [response, setResponse] = useState({}); // response from ROS

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


  return (
    <>
      <p>Connection Status: {connection}</p>
      <InputForm rosRequest={rosRequest} setRosRequest={setRosRequest} working={working} setWorking={setWorking} setResponse={setResponse} />
      <p>ROS Request: {JSON.stringify(rosRequest)}</p>
      <p>Response: {JSON.stringify(response.response)}</p>
      <CanvasProvider width={rosRequest.boxwidth || 512} height={rosRequest.boxheight || 512} Request={rosRequest} change={setDrawObj}>
        <Disc x={drawObj.alphax} y={drawObj.alphay} r={drawObj.r0} color={"#C4E4FF"} trigger={drawObj} />
        <Disc x={drawObj.betax} y={drawObj.betay} r={drawObj.r0} color={"pink"} trigger={drawObj} />
      </CanvasProvider>
    </>
  )
};

export default App;