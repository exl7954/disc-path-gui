import React, { createContext, useContext, useEffect, useRef } from "react";
import "./Canvas.css";

const CanvasContext = createContext();
const CanvasLowerContext = createContext();

export const useCanvas = () => useContext(CanvasContext);
export const useCanvasLower = () => useContext(CanvasLowerContext);

export const CanvasProvider = ({ width, height, Request, setDrawObj, children }) => {
    const canvasRef = useRef(null);
    const draw = (drawFunction) => {
        const canvas = canvasRef.current;
        const ctx = canvas.getContext("2d");
        drawFunction(ctx);
    };

    const lowerRef = useRef(null);
    const drawLower = (drawFunction) => {
        const lowerCanvas = lowerRef.current;
        const lowerCtx = lowerCanvas.getContext("2d");
        drawFunction(lowerCtx);
    };

    useEffect(() => {
        const canvas = canvasRef.current;
        const ctx = canvas.getContext("2d");
        ctx.clearRect(0, 0, width, height);

        const lowerCanvas = lowerRef.current;
        const lowerCtx = lowerCanvas.getContext("2d");
        lowerCtx.clearRect(0, 0, width, height);

        setDrawObj({...Request})
    }, [Request]);
    
    let transformString = "translateX(" + -width/2 + "px)";
    return (
        <div className="canvas-container">
            <CanvasLowerContext.Provider value={{ drawLower }}>
                <CanvasContext.Provider value={{ draw }}>
                    <div className="layer-container">
                        <canvas
                            ref={canvasRef}
                            width={width}
                            height={height}
                            className="top-canvas"
                            style={{transform: transformString, zIndex: 1}}
                        />
                        <canvas 
                            ref={lowerRef}
                            width={width}
                            height={height}
                            className="bottom-canvas"
                            
                            style={{transform: transformString, zIndex: 0}}
                        />
                    </div>
                    
                    {children}
                </CanvasContext.Provider>
            </CanvasLowerContext.Provider>
        </div>
    );
};