import React, { useState } from "react";
import { CanvasProvider } from "./components/CanvasProvider";
import InputForm from "./components/InputForm";
import "./App.css";

function App() {
  // connect to ROS
  const [connection, setConnection] = useState("closed");
  const [rosRequest, setRosRequest] = useState({});


  return (
    <>
      <p>Connection Status: {connection}</p>
      <InputForm rosRequest={rosRequest} setRosRequest={setRosRequest} />
      <p>ROS Request: {JSON.stringify(rosRequest)}</p>
      <CanvasProvider width={rosRequest.boxwidth || 512} height={rosRequest.boxheight || 512}>
      </CanvasProvider>
    </>
  )
};

export default App;