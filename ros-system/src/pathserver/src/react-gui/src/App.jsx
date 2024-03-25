import React, { useState } from "react";
import { CanvasProvider } from "./components/CanvasProvider";
import Rectangle from "./components/Rectangle";
import Polygon from "./components/Polygon";
import Path from "./components/Path";
import { RosProcessor } from "./components/RosProcessor";
import { generateBox, generatePolygon, processessOutPut } from "./components/methods";
import { FileUploader } from "./components/FileUploader";
import "./App.css";

function App() {
  const [input, setInput] = useState(null);
  const [show, setShow] = useState(false);
  const [result, setResult] = useState(null);

  const showData = () => {
    setShow(true);
  };

  const test = () => {
    if (result) {
      console.log(result);
    }
  }

  return (
    <>
      <FileUploader func={setInput}></FileUploader>
      <CanvasProvider width={512} height={512}>
        {show && generatePolygon(input)}
        {result && generateBox(processessOutPut(result).boxes)}
        {result && <Path points={processessOutPut(result).path} />}
      </CanvasProvider>
      <button onClick={showData}>Start</button>
      <RosProcessor func={setResult} />
    </>
  )
};

export default App;