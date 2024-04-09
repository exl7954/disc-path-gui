import React, { useState } from "react";
import { CanvasProvider } from "../CanvasProvider";
import Polygon from "../Polygon";
import Disc from "../Disc";
import Rectangle from "../Rectangle";
import { Path } from "../Path";
import { generateBox } from "../methods";

export function ResultCanvas({ requestObj, resultObj }) {
    if (!resultObj) {
        return null;
    }
    let drawingObj = { ...requestObj, ...resultObj };
    let [emptyObj, setEmptyObj] = useState({});
    let [showPolygons, setShowPolygons] = useState(false);
    let [showDisc, setShowDisc] = useState(false);
    let [showPath, setShowPath] = useState(false);

    function start(input) {
        let result = generateBox(input);
        setShowPolygons(true);
        return result;
    }

    return <div>
        <CanvasProvider height={requestObj.boxheight} width={requestObj.boxwidth} Request={{ setEmptyObj }} >
        // 先画正方形
            {start(drawingObj.boxes)}
        // 画Polygons
            {showPolygons && console.log()}
        // 画Disc

        // 画Path

        </CanvasProvider>
    </div>

};