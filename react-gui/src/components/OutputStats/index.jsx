import React, { useState, useEffect } from 'react';
import './OutputStats.css';

export default function OutputStats({rosRequest, response, containerRef}) {
    const [isOpen, setIsOpen] = useState(false);
    const [leftmargin, setLeftMargin] = useState(0);

    function toggle() {
        setIsOpen(!isOpen);
    }

    useEffect(() => {
        const handleResize = () => {
            if (containerRef.current) {
                let boxOffset = !rosRequest.boxwidth ? 256 : rosRequest.boxwidth / 2;
                setLeftMargin(containerRef.current.clientWidth / 2 + boxOffset + 10);
            }
        };

        // Run on mount and on resize
        handleResize(); // Set initial values
        window.addEventListener('resize', handleResize);

        // Cleanup function to remove the event listener
        return () => {
            window.removeEventListener('resize', handleResize);
        };
    }, [rosRequest, containerRef]);

    useEffect(() => {
        if (!response.elapsedtime) {
            setIsOpen(false);
        }
    }, [response]);

    return (
        <div className={`output-stats ${isOpen ? 'expanded' : ''} ${response.elapsedtime == undefined ? 'disabled' : ''}`}
            style={{ marginLeft: leftmargin }}
        >
            <button className="toggle" disabled={response.elapsedtime == undefined ? true : false} onClick={toggle}>

            {isOpen ? 
            <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor" className="w-6 h-6">
                <path d="M18.375 2.25c-1.035 0-1.875.84-1.875 1.875v15.75c0 1.035.84 1.875 1.875 1.875h.75c1.035 0 1.875-.84 1.875-1.875V4.125c0-1.036-.84-1.875-1.875-1.875h-.75ZM9.75 8.625c0-1.036.84-1.875 1.875-1.875h.75c1.036 0 1.875.84 1.875 1.875v11.25c0 1.035-.84 1.875-1.875 1.875h-.75a1.875 1.875 0 0 1-1.875-1.875V8.625ZM3 13.125c0-1.036.84-1.875 1.875-1.875h.75c1.036 0 1.875.84 1.875 1.875v6.75c0 1.035-.84 1.875-1.875 1.875h-.75A1.875 1.875 0 0 1 3 19.875v-6.75Z" />
            </svg> 
            : 
            <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth={1.5} stroke="currentColor" className="w-6 h-6">
                <path strokeLinecap="round" strokeLinejoin="round" d="M3 13.125C3 12.504 3.504 12 4.125 12h2.25c.621 0 1.125.504 1.125 1.125v6.75C7.5 20.496 6.996 21 6.375 21h-2.25A1.125 1.125 0 0 1 3 19.875v-6.75ZM9.75 8.625c0-.621.504-1.125 1.125-1.125h2.25c.621 0 1.125.504 1.125 1.125v11.25c0 .621-.504 1.125-1.125 1.125h-2.25a1.125 1.125 0 0 1-1.125-1.125V8.625ZM16.5 4.125c0-.621.504-1.125 1.125-1.125h2.25C20.496 3 21 3.504 21 4.125v15.75c0 .621-.504 1.125-1.125 1.125h-2.25a1.125 1.125 0 0 1-1.125-1.125V4.125Z" />
            </svg>
            }

            </button>
            <div className="output-stats-content" id="container-content" style={{ maxHeight: isOpen ? `${document.getElementById('container-content').scrollHeight}px` : '0' }}>
                <p>Elapsed Time: {response.elapsedtime}</p>
                <p>Times Expanded: {response.expandcount}</p>
                <p>Total Free Boxes: {response.totalfree}</p>
                <p>Total Stuck Boxes: {response.totalstuck}</p>
                <p>Mixed Boxes Smaller Than Epsilon: {response.mixsmaller}</p>
                <p>Mixed Boxes Larger Than Epsilon: {response.mixbigger}</p>
            </div>
            
        </div>
    );
}