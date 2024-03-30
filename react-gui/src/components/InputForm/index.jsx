import "./InputForm.css";



export default function InputForm({rosRequest, setRosRequest}) {
    function handleSubmit(e) {
        e.preventDefault();
        const form = e.target;
        const formData = new FormData(form);
        const formJson = Object.fromEntries(formData.entries());
        console.log(formJson);
    }

    function TextInput(name, label, inputType) {
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
                <label>{label}</label>
                <input name={name} type={inputType} onChange={handleInputChange} />
            </div>
        );
    }

    return (
        <div className="input-form">
            <form onSubmit={handleSubmit}>
            <div className="disk-input flex-child">
                {TextInput("alpha", "Alpha", "text")}
                {TextInput("beta", "Beta", "text")}
                {TextInput("epsilon", "Epsilon", "number")}
                {TextInput("radius", "R0", "number")}
            </div>
            <div className="environment-input flex-child">
                {TextInput("boxwidth", "Box Width", "number")}
                {TextInput("boxheight", "Box Height", "number")}
                {TextInput("points", "Points", "text")}
                {TextInput("polygons", "Polygons", "text")}
            </div>
            <div className="alg-input flex-child">
                {TextInput("qtype", "QType", "number")}
                {TextInput("seed", "Random Seed", "number")}
            </div>
                
                <button type="submit">Submit</button>
            </form>
        </div>
    );
}