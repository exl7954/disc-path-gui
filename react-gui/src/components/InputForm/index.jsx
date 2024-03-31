import React, { useState } from "react";
import "./InputForm.css";



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
                <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/cc/Cross_red_circle.svg/2048px-Cross_red_circle.svg.png" alt="red x"></img> Invalid Input
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
        
        return (
            <div className="text-input" id={props.name}>
                <label>{props.label}</label>
                <input name={props.name} type={props.inputType} onChange={handleInputChange} />
            </div>
        );
    }

    return (
        <>
        <div className="input-form">
            <form onSubmit={handleSubmit}>
            <div className="disk-input flex-child">
                {TextInput({name: "alphax", label: "Alpha X", inputType: "number", setInvalidInput: setInvalidInput})}
                {TextInput({name: "alphay", label: "Alpha Y", inputType: "number"})}
                {TextInput({name: "betax", label: "Beta X", inputType: "number"})}
                {TextInput({name: "betay", label: "Beta Y", inputType: "number"})}
                {TextInput({name: "epsilon", label: "Epsilon", inputType: "number"})}
                {TextInput({name: "radius", label: "Radius", inputType: "number"})}
            </div>
            <div className="environment-input flex-child">
                {TextInput({name: "boxwidth", label: "Box Width", inputType: "number"})}
                {TextInput({name: "boxheight", label: "Box Height", inputType: "number"})}
                {TextInput({name: "points", label: "Points", inputType: "text"})}
                {TextInput({name: "polygons", label: "Polygons", inputType: "text"})}
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