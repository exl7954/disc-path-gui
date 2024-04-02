import React, { useState } from "react";
import "./InputForm.css";
import { Tooltip } from 'react-tooltip';
import red_x from "../assets/red_x.png";


export default function InputForm({rosRequest, setRosRequest}) {
    const [invalidInput, setInvalidInput] = useState(false);
    const [errorMessage, setErrorMessage] = useState(null);

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
            
            setRosRequest(formJson);
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
        }
        // if tooltipId is passed in, create a tooltip
        return (
            <div className="text-input" id={props.name}>
                <div className="input-label">
                    <label>{props.label}</label>
                    {"tooltipId" in props ? <img src="https://icons.veryicon.com/png/o/miscellaneous/official-icon-of-flying-pig/question-mark-is-small.png" alt="info" data-tooltip-id={props.tooltipId} data-tooltip-content={props.tooltipContent}></img> : null}
                </div>
                <input name={props.name} type={props.inputType} onChange={handleInputChange} />
                <Tooltip id={props.tooltipId} place="top" type="dark" effect="solid" />
            </div>
        );
    }

    return (
        <>
        <div className="input-form">
            <form onSubmit={handleSubmit}>
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
                    <select id="qtype" name="qtype" onChange={e => setRosRequest({...rosRequest, qtype: e.target.value})}>
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
                }}>Reset</button>
            </form>
        </div>
        <div>{invalidInput ? <InvalidInput /> :null}</div>
        </>
    );
}