import './TimelineSlider.css';
import { useState, useEffect } from 'react';

export default function TimelineSlider({ setStopPoint, stopPoint, response, containerRef, rosRequest }) {
    const [totalBoxes, setTotalBoxes] = useState(100);
    const [topOffset, setTopOffset] = useState(0);
    const [playing, setPlaying] = useState(false);
    
    useEffect(() => {
        if (response && response.boxtimeline) {
            setTotalBoxes(response.boxtimeline.match(/\|/g).length);
            setStopPoint(-1);
        }
    }, [response])

    useEffect(() => {
        const handleResize = () => {
            if (containerRef.current) {
                let boxHeight = !rosRequest.boxheight ? 512 : parseInt(rosRequest.boxheight);
                setTopOffset(window.scrollY + containerRef.current.getBoundingClientRect().top + boxHeight + 30);
            }
        };
        // Run on mount and on resize
        handleResize(); // Set initial values
        window.addEventListener('resize', handleResize);

        // Cleanup function to remove the event listener
        return () => {
            window.removeEventListener('resize', handleResize);
        };
        
    
    }, [rosRequest, containerRef])



    function togglePlaying() {
        setPlaying(!playing);
    }

    function calculateStep(totalBoxes) {
        if (totalBoxes < 1000) {
            return 1;
        }
        // want to have around 800 steps max
        return Math.ceil(totalBoxes / 800);
    }

    return (
        <div className="slider-container" style={{top: `${topOffset}px`}} >
            <input  type="range" 
                    min="0" 
                    max={totalBoxes}
                    step={calculateStep(totalBoxes)}
                    value={stopPoint == -1 ? totalBoxes : stopPoint} 
                    onChange={(e) => setStopPoint(e.target.value)} 
                    disabled={response.boxtimeline ? false : true}
                    className="timeline-slider" />
        </div>
    );
}