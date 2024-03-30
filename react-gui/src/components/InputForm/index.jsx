import "./InputForm.css";



export default function InputForm({rosRequest, setRosRequest}) {
    function handleSubmit(e) {
        e.preventDefault();
        const form = e.target;
        const formData = new FormData(form);
        const formJson = Object.fromEntries(formData.entries());
        console.log(formJson);
    }

    function TextInput(props) {
        function handleInputChange(event) {
            const target = event.target;
            const value = target.value;
            const name = target.name;
    
            setRosRequest({
                ...rosRequest,
                [name]: value
            });
    
            console.log(rosRequest)
        }
        
        return (
            <div className="text-input">
                <label>{props.label}</label>
                <input name={props.name} type={props.inputType} onChange={handleInputChange} />
            </div>
        );
    }

    return (
        <div className="input-form">
            <form onSubmit={handleSubmit}>
            <div className="disk-input flex-child">
                {TextInput({name: "alphax", label: "Alpha X", inputType: "number"})}
                {TextInput({name: "alphay", label: "Alpha Y", inputType: "number"})}
                {TextInput({name: "betax", label: "Beta X", inputType: "number"})}
                {TextInput({name: "betay", label: "Beta Y", inputType: "number"})}
                {TextInput({name: "epsilon", label: "Epsilon", inputType: "number"})}
                {TextInput({name: "radius", label: "R0", inputType: "number"})}
            </div>
            <div className="environment-input flex-child">
                {TextInput({name: "boxwidth", label: "Box Width", inputType: "number"})}
                {TextInput({name: "boxheight", label: "Box Height", inputType: "number"})}
                {TextInput({name: "points", label: "Points", inputType: "text"})}
                {TextInput({name: "polygons", label: "Polygons", inputType: "text"})}
            </div>
            <div className="alg-input flex-child">
                {TextInput({name: "qtype", label: "QType", inputType: "number"})}
                {TextInput({name: "seed", label: "Random Seed", inputType: "number"})}
            </div>
                
                <button type="submit">Submit</button>
            </form>
        </div>
    );
}