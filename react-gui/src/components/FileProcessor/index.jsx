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
                    event.target.value = '';
                }
            }
            // txt file from old format
            if (file.type === "text/plain") {
                // read lines from txt
                let lines = content.split("\n");
                // trim lines, remove leading tabs, and ignore empty lines and # lines
                lines = lines.map(line => line.trim())
                             .map(line => line.replace(/^\t+/, ""))
                             .filter(line => line.length > 0 && !line.startsWith("#"));

                // first line is numpts
                try {
                    let numpts = parseInt(lines[0]);
                    let pts = "";
                    for (let i = 1; i <= numpts; i++) {
                        pts += lines[i].replace(" ", ",") + "|";
                    }
                    pts = pts.slice(0, -1);

                    let numpolygons = parseInt(lines[numpts + 1]);
                    let polygons = "";
                    for (let i = numpts + 2; i < lines.length; i++) {
                        // if last character is '\' then next line is continuation
                        if (lines[i].endsWith("\\")) {
                            polygons += lines[i].slice(0, -1).replaceAll(" ", ",");
                        } else {
                            polygons += lines[i].replaceAll(" ", ",") + "|";
                        }
                    }
                    polygons = polygons.slice(0, -1);
                    setExternalChange({numpts: numpts, pts: pts, numpolygons: numpolygons, polygons: polygons})
                } catch(e) {
                    console.error("INVALID TXT FORMAT: ", e);
                    event.target.value = '';
                }
                
            }
            event.target.value = '';
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
        <button className="file-button upload" onClick={()=>fileInputRef.current.click()}>
            <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth={1.5} stroke="currentColor" className="w-6 h-6">
            <path strokeLinecap="round" strokeLinejoin="round" d="M3 16.5v2.25A2.25 2.25 0 0 0 5.25 21h13.5A2.25 2.25 0 0 0 21 18.75V16.5m-13.5-9L12 3m0 0 4.5 4.5M12 3v13.5" />
            </svg>

            Upload Input</button>
        <button className="file-button download" onClick={handleDownload}>
            <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth={1.5} stroke="currentColor" className="w-6 h-6">
            <path strokeLinecap="round" strokeLinejoin="round" d="M3 16.5v2.25A2.25 2.25 0 0 0 5.25 21h13.5A2.25 2.25 0 0 0 21 18.75V16.5M16.5 12 12 16.5m0 0L7.5 12m4.5 4.5V3" />
            </svg>

            Save Input</button>
        </div>
    );
}