function TextInput(name, label, inputType) {
    return (
        <div>
            <label>{label}</label><br></br>
            <input name={name} type={inputType} />
        </div>
    );
}

export default function InputForm() {
    function handleSubmit(e) {
        e.preventDefault();
        const form = e.target;
        const formData = new FormData(form);
        const formJson = Object.fromEntries(formData.entries());
        console.log(formJson);
    }

    return (
        <div className="input-form">
            <form onSubmit={handleSubmit}>
            <fieldset>
                <legend>Disk</legend>
                {TextInput("alpha", "Alpha", "text")}
                {TextInput("beta", "Beta", "text")}
                {TextInput("epsilon", "Epsilon", "number")}
                {TextInput("radius", "R0", "number")}
            </fieldset>
            <fieldset>
                <legend>Environment</legend>
                {TextInput("boxwidth", "Box Width", "number")}
                {TextInput("boxheight", "Box Height", "number")}
                {TextInput("points", "Points", "text")}
                {TextInput("polygons", "Polygons", "text")}
            </fieldset>
            <fieldset>
                <legend>Algorithm</legend>
                {TextInput("qtype", "QType", "number")}
                {TextInput("seed", "Random Seed", "number")}
            </fieldset>
                
                <button type="submit">Submit</button>
            </form>
        </div>
    );
}