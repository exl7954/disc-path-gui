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
        console.log(box_color);
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

export function readInput(input) {
    let content = input.split("\n");
    content = content.map((ele) => {
        return ele.split(" ");
    });
    content = content.map((ele) => {
        let temp = ele.map((element) => {
            return parseInt(element);
        });
        return temp;
    });
    content = content.filter((array) => {
        let result = array.reduce((old, ele) => {
            if (isNaN(ele)) {
                return false;
            }
            return old;
        }, true);
        return result;
    })
    return content;
};

export function readPolygon(input) {
    input = readInput(input);
    let numPoints = input[0][0];
    let numPolygons = input[numPoints + 1][0];
    let points = [];
    let polygons = [];
    for (let i = 1; i < numPoints + 1; i++) {
        points.push(input[i]);
    }
    for (let i = numPoints + 2; i < numPoints + numPolygons + 2; i++) {
        let poly = input[i];
        let temp = [];
        for (let j = 0; j < poly.length; j++) {
            temp.push(points[poly[j] - 1]);
        }
        polygons.push(temp);
    }
    return polygons;
};

export function generatePolygon(input) {
    let result = input.map((point) => {
        let i = 0;
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