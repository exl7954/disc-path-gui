import React, { useState, useEffect } from "react";
import "./InputForm.css";
import { Tooltip } from 'react-tooltip';
import red_x from "../assets/red_x.png";


export default function InputForm({rosRequest, setRosRequest, working, setWorking, setResponse, externalChange, setExternalChange}) {
    const [invalidInput, setInvalidInput] = useState(false);
    const [errorMessage, setErrorMessage] = useState(null);

    useEffect(() => {
        if (Object.keys(externalChange).length != 0) {
            for (const key in externalChange) {
                // set text input to key value
                if (key != "alpha" && key != "bta") {
                    document.getElementsByName(key)[0].value = externalChange[key];
                }
            }
            setRosRequest({...rosRequest, ...externalChange})
            setExternalChange({});
        }
    }, [externalChange])

    function handleSubmit(e) {
        e.preventDefault();
        const form = e.target;
        const formData = new FormData(form);
        const formJson = Object.fromEntries(formData.entries());
        let canSubmit = true;
        let checkResult = checkInput(formJson);
        if (checkResult != "valid") {
            setInvalidInput(true);
            setErrorMessage(checkResult);
            canSubmit = false;
        }

        // canSubmit to keep track of whether the form can be submitted because setInvalidInput is async
        if (canSubmit == true) {
            // FORMAT REQUEST
            // convert all values to integers
            Object.keys(formJson).map(key => {
                if (key != "pts" && key != "polygons") {
                    formJson[key] = parseInt(formJson[key]);
                }
            })

            // format alpha and beta
            formJson["alpha"] = [formJson["alphax"], formJson["alphay"]];
            formJson["bta"] = [formJson["betax"], formJson["betay"]];
            delete formJson["alphax"];
            delete formJson["alphay"];
            delete formJson["betax"];
            delete formJson["betay"];

            // add numPts and numPolygons
            formJson["numpts"] = formJson["pts"].split("|").length;
            formJson["numpolygons"] = formJson["polygons"].split("|").length;

            // add view params (unused)
            formJson["deltax"] = 0;
            formJson["deltay"] = 0;
            formJson["scale"] = 1;

            setRosRequest(formJson);
            setWorking(true);
        }
    }

    function checkInput(formJson) {
        // check for empty values
        for (const key in formJson) {
            if (formJson[key] === "") {
                return "Empty Field(s)";
            }
        }

        // check for invalid epsilon and radius and box dimensions
        if (parseInt(formJson.epsilon) <= 0) {
            return "Epsilon must be greater than 0";
        }
        if (parseInt(formJson.radius) <= 0) {
            return "Radius must be greater than 0";
        }
        if (parseInt(formJson.boxwidth) <= 0 || parseInt(formJson.boxwidth) > 1500) {
            return "Box width out of bounds";
        }
        if (parseInt(formJson.boxheight) <= 0 || parseInt(formJson.boxheight) > 1500) {
            return "Box height out of bounds";
        }

        // check for out of bounds alpha and beta
        if (parseInt(formJson.alphax) < 0 || parseInt(formJson.alphax) > parseInt(formJson.boxwidth)) {
            return "Alpha X out of bounds";
        }
        if (parseInt(formJson.alphay) < 0 || parseInt(formJson.alphay) > parseInt(formJson.boxheight)) {
            return "Alpha Y out of bounds";
        }
        if (parseInt(formJson.betax) < 0 || parseInt(formJson.betax) > parseInt(formJson.boxwidth)) {
            return "Beta X out of bounds";
        }
        if (parseInt(formJson.betay) < 0 || parseInt(formJson.betay) > parseInt(formJson.boxheight)) {
            return "Beta Y out of bounds";
        }

        // check points and polygons
        const re = /[^\d,|]/
        
        if (String(formJson.pts).search(re) != -1) {
            return "Invalid Points";
        }
        if (String(formJson.polygons).search(re) != -1) {
            return "Invalid Polygons";
        }
        // check to make sure points are in the correct format
        let counter = 0;
        let currentNum = "";
        for (let i = 0; i < formJson.pts.length; i++) {
            if (formJson.pts[i] == ",") {
                if (currentNum == "") {
                    return "Invalid Points";
                } else if (parseInt(currentNum) < 0 || parseInt(currentNum) > parseInt(formJson.boxwidth)) {
                    return "Out of bounds point";
                }
                currentNum = "";
                counter++;
            } else if (formJson.pts[i] == "|" || i == formJson.pts.length - 1) {
                if (i == formJson.pts.length - 1) {currentNum += formJson.pts[i];}
                if (currentNum == "") {
                    return "Invalid Points";
                } else if (parseInt(currentNum) < 0 || parseInt(currentNum) > parseInt(formJson.boxheight)) {
                    return "Out of bounds point";
                } else if (counter != 1) {
                    return "Invalid Points";
                }
                currentNum = "";
                counter = 0;
            } else {
                currentNum += formJson.pts[i];
            }
        }

        // check to make sure polygons are in the correct format
        const numPts = formJson.pts.split("|").length;
        let polygonArray = formJson.polygons.split("|");
        if (polygonArray.includes(undefined) || polygonArray.includes("")) {
            return "Invalid Polygons";
        }
        for (let i = 0; i < polygonArray.length; i++) {
            let arr = polygonArray[i].split(",");
            if (arr.includes(undefined) || arr.includes("")) {
                return "Invalid Polygons";
            }
            if (new Set(arr).size < 3) {
                return "Polygon must have at least 3 unique points";
            }
            if (Math.max(...arr) > numPts) {
                return "Polygon contains invalid point";
            }
            if (Math.min(...arr) <= 0) {
                return "Polygon contains invalid point";
            }
            if (arr[0] != arr[arr.length - 1]) {
                return "Polygon must be closed";
            }
        }

        // valid input
        return "valid";
    }

    function InvalidInput() {
        return (
            <div className="invalid-input">
                <img src={red_x} alt="red x"></img> Invalid Input: {errorMessage}
            </div>
        );
    }

    function TextInput(props) {
        function handleInputChange(event) {
            const target = event.target;
            const value = target.value;
            const name = target.name;
            setInvalidInput(false);
            setErrorMessage(null);
            setRosRequest({
                ...rosRequest,
                [name]: value
            });
            setResponse({});
            if (value == "") {
                setRosRequest({
                    ...rosRequest,
                    [name]: undefined
                });
            } else {
                if (name == "alphax" || name == "alphay") {
                    if (rosRequest["alpha"] != undefined) {
                        if (name == "alphax") {
                            setRosRequest({
                                ...rosRequest,
                                alpha: [value, rosRequest["alpha"][1]]
                            });
                        }
                        if (name == "alphay") {
                            setRosRequest({
                                ...rosRequest,
                                alpha: [rosRequest["alpha"][0], value]
                            });
                        }
                    }
                }
                if (name == "betax" || name == "betay") {
                    if (rosRequest["bta"] != undefined) {
                        if (name == "betax") {
                            setRosRequest({
                                ...rosRequest,
                                bta: [value, rosRequest["bta"][1]]
                            });
                        }
                        if (name == "betay") {
                            setRosRequest({
                                ...rosRequest,
                                bta: [rosRequest["bta"][0], value]
                            });
                        }
                    }
                }
            }
            
        }
        // if tooltipId is passed in, create a tooltip
        return (
            <div className="text-input" id={props.name}>
                <div className="input-label">
                    <label>{props.label}</label>
                    {"tooltipId" in props ? <img src="https://icons.veryicon.com/png/o/miscellaneous/official-icon-of-flying-pig/question-mark-is-small.png" alt="info" data-tooltip-id={props.tooltipId} data-tooltip-content={props.tooltipContent}></img> : null}
                </div>
                <input name={props.name} type={props.inputType} autoComplete="off" onChange={handleInputChange} />
                <Tooltip id={props.tooltipId} place="top" type="dark" effect="solid" />
            </div>
        );
    }

    return (
        <>
        <div className="input-form">
            <form onSubmit={handleSubmit}>
            <fieldset disabled={working}>
            <div className="disk-input flex-child">
                {TextInput({name: "alphax", label: "Alpha X", inputType: "number", tooltipId: "alphax-tooltip", tooltipContent: "Starting Coordinates"})}
                {TextInput({name: "alphay", label: "Alpha Y", inputType: "number"})}
                {TextInput({name: "betax", label: "Beta X", inputType: "number", tooltipId: "betax-tooltip", tooltipContent: "Ending Coordinates"})}
                {TextInput({name: "betay", label: "Beta Y", inputType: "number"})}
                {TextInput({name: "epsilon", label: "Epsilon", inputType: "number", tooltipId: "epsilon-tooltip", tooltipContent: "Minimum Box Size for Subdivision"})}
                {TextInput({name: "r0", label: "Radius", inputType: "number"})}
            </div>
            <div className="environment-input flex-child">
                {TextInput({name: "boxwidth", label: "Box Width", inputType: "number"})}
                {TextInput({name: "boxheight", label: "Box Height", inputType: "number"})}
                {TextInput({name: "pts", label: "Points", inputType: "text", tooltipId: "points-tooltip", tooltipContent: "Points should be in the format: x1,y1|x2,y2|x3,y3..."})}
                {TextInput({name: "polygons", label: "Polygons", inputType: "text", tooltipId: "polygons-tooltip", tooltipContent: "Polygons should be in the format: v1,v2,v3|v1,v2,v3,v4|..."})}
                {TextInput({name: "seed", label: "Random Seed", inputType: "number"})}
                <div className="text-input">
                    <label>QType</label>
                    <select id="qtype" name="qtype" onChange={e => {
                        setRosRequest({...rosRequest, qtype: e.target.value});
                        setResponse({});
                        setInvalidInput(false);
                        setErrorMessage(null);
                    }}>
                        <option value="0">Random</option>
                        <option value="1">Sequential</option>
                        <option value="2">Dijkstra</option>
                    </select>
                </div>
                
            </div>
                <button id="submit-button" type="submit">Submit</button>
                <button id="reset-button" type="reset" onClick={() => {
                    setRosRequest({}); 
                    setInvalidInput(false);
                    setErrorMessage(null);
                    setResponse({});
                }}>Reset</button>
            </fieldset>
            </form>
        </div>
        <div>{invalidInput ? <InvalidInput /> :null}</div>
        </>
    );
}