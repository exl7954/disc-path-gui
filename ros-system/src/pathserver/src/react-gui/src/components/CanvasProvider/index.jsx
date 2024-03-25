import React, { createContext, useContext, useRef } from "react";
import "./Canvas.css";

const CanvasContext = createContext();

export const useCanvas = () => useContext(CanvasContext);

export const CanvasProvider = ({ width, height, children }) => {
    const canvasRef = useRef(null);
    const draw = (drawFunction) => {
        const canvas = canvasRef.current;
        const ctx = canvas.getContext("2d");
        drawFunction(ctx);
    };

    return (
        <div className="canvas-container">
            <CanvasContext.Provider value={{ draw }}>
                <canvas
                    ref={canvasRef}
                    width={width}
                    height={height}
                    className="canvas"
                />
                {children}
            </CanvasContext.Provider>
        </div>
    );
};