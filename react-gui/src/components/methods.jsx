import React from "react";
import Rectangle from "./Rectangle";
import Polygon from "./Polygon";

export function parseBox(box) {
    let boxes = box.split("|");
    boxes = boxes.map((element) => element.split(/[,!]/));
    return boxes
}

export function generateBox(input) {
    input = parseBox(input);
    let i = 0;
    let result = input.map(([x, y, width, height, color]) => {
        let box_color = "grey"
        if (color == 0) {
            box_color = "green";
        }
        if (color == 1) {
            box_color = "red";
        }
        if (color == 2) {
            box_color = "yellow";
        }
        return (
            <Rectangle
                x={parseInt(x)}
                y={parseInt(y)}
                width={parseInt(width)}
                height={parseInt(height)}
                color={box_color}
                key={i++}
            />
        )
    });
    return result;
};

export function parsePoints(ptsString) {
    if (!ptsString) return [];
    return ptsString.split('|').map(pt =>
        pt.split(',')
            .map(str => str.trim())
            .filter(str => str !== '')
            .map(Number)
            .filter(num => !isNaN(num))
    ).filter(arr => arr.length > 0);
}

export function parsePolygons(polygonsString, points) {
    if (!polygonsString) return [];
    return polygonsString.split('|').map(polygon => {
        return polygon.split(',')
            .map(str => str.trim())
            .filter(str => str !== '' && !isNaN(str))
            .map(ptIndex => {
                const index = parseInt(ptIndex, 10) - 1;
                return index >= 0 && index < points.length ? points[index] : null;
            })
            .filter(pt => pt !== null);
    }).filter(polygon => polygon.length > 0);
}


export function readPolygon(drawObj) {
    const points = parsePoints(drawObj.pts);
    const polygons = parsePolygons(drawObj.polygons, points);
    return polygons;
};

let i = 0;
export function generatePolygon(input) {
    let result = input.map((point) => {
        return <Polygon color="black" points={point} key={i++}></Polygon>;;
    });
    return result;
};

export function processessOutPut(output) {
    if (output.response === "true") {
        return {
            boxes: output.boxes,
            path: output.path
        }
    }
    else {
        return false
    }
};

export function processPath(input) {
    let path = input.split('|')
        .map((x) => x.trim())
        .filter((arr) => arr.length > 1)
        .map(p => p.split(' '))
        .map(p => p.map((x) => parseInt(x)));
    return path;
};