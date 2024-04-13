import React, { useState, useRef } from 'react';
import './FileProcessor.css';

export default function FileProcessor({rosRequest, setRosRequest, setExternalChange}) {
    const fileInputRef = useRef();

    function handleUpload(event) {
        const file = event.target.files[0];
        const reader = new FileReader();
        reader.onload = (e) => {
            const content = e.target.result;
            // json file downloaded from program
            if (file.type === "application/json") {
                try {
                    const request = JSON.parse(content);
                    setExternalChange(request);
                } catch (e) {
                    console.error(e);
                }
            }
            // txt file from old format
            if (file.type === "text/plain") {
                
            }
            
        };
        reader.readAsText(file);
    }
  
    function handleDownload() {
        // don't download if request is empty or has no non null fields
        if (Object.keys(rosRequest).length == 0 || Object.values(rosRequest).every(v => v == "" || v == undefined)) {
            return;
        }

        const file = new File([JSON.stringify(rosRequest)], "request.json", {type: "application/json"});
        const link = document.createElement('a')
        const url = URL.createObjectURL(file)

        link.href = url
        link.download = file.name
        document.body.appendChild(link)
        link.click()

        document.body.removeChild(link)
        window.URL.revokeObjectURL(url)
    }

    return (
        <div className="file-processor">
        <input hidden id="fileInput" multiple={false} type="file" accept=".txt, .json" ref={fileInputRef} onChange={handleUpload} />
        <button onClick={()=>fileInputRef.current.click()}>Upload Request</button>
        <button onClick={handleDownload}>Download Request</button>
        </div>
    );
}