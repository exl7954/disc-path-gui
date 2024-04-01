import React, { useState } from "react";
import "./InputForm.css";
import { Tooltip } from 'react-tooltip';
import red_x from "../assets/red_x.png";


export default function InputForm({rosRequest, setRosRequest}) {
    const [invalidInput, setInvalidInput] = useState(false);

    function handleSubmit(e) {
        e.preventDefault();
        const form = e.target;
        const formData = new FormData(form);
        const formJson = Object.fromEntries(formData.entries());
        let canSubmit = true;
        for (const key in formJson) {
            if (formJson[key] === "") {
                console.log("empty key")
                setInvalidInput(true);
                canSubmit = false;
                break;
            }
        }
        // canSubmit to keep track of whether the form can be submitted because setInvalidInput is async
        if (canSubmit == true) {setRosRequest(formJson);}
    }

    function InvalidInput() {
        return (
            <div className="invalid-input">
                <img src={red_x} alt="red x"></img> Invalid Input
            </div>
        );
    }

    function TextInput(props) {
        function handleInputChange(event) {
            const target = event.target;
            const value = target.value;
            const name = target.name;
            setInvalidInput(false);
            setRosRequest({
                ...rosRequest,
                [name]: value
            });
    
            console.log(rosRequest)
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
                {TextInput({name: "radius", label: "Radius", inputType: "number"})}
            </div>
            <div className="environment-input flex-child">
                {TextInput({name: "boxwidth", label: "Box Width", inputType: "number"})}
                {TextInput({name: "boxheight", label: "Box Height", inputType: "number"})}
                {TextInput({name: "points", label: "Points", inputType: "text", tooltipId: "points-tooltip", tooltipContent: "Points should be in the format: x1,y1|x2,y2|x3,y3..."})}
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
                <button type="submit">Submit</button>
                <button type="reset" onClick={() => {setRosRequest({}); setInvalidInput(false)}}>Reset</button>
            </form>
        </div>
        <div>{invalidInput ? <InvalidInput /> :null}</div>
        </>
    );
}