import React, { useState } from "react";
import { readPolygon } from './methods';

export function FileUploader(props) {
    const [selectedFile, setSelectedFile] = useState(null);

    const handleFileChange = (event) => {
        const file = event.target.files[0];
        setSelectedFile(file);
    };

    const handleFileRead = () => {
        if (selectedFile) {
            const reader = new FileReader();

            reader.onload = (event) => {
                props.func(readPolygon(event.target.result));
            };

            reader.readAsText(selectedFile);
        }
    };

    return (
        <div>
            <input type="file" onChange={handleFileChange} />
            <button onClick={handleFileRead}>Read File</button>
            {selectedFile && <p>File Name: {selectedFile.name}</p>}
        </div>
    )
};