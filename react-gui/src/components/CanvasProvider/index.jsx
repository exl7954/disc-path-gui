import React, { createContext, useContext, useEffect, useRef } from "react";
import "./Canvas.css";

const CanvasContext = createContext();

export const useCanvas = () => useContext(CanvasContext);

export const CanvasProvider = ({ width, height, Request, change, children }) => {
    const canvasRef = useRef(null);
    const draw = (drawFunction) => {
        const canvas = canvasRef.current;
        const ctx = canvas.getContext("2d");
        drawFunction(ctx);
    };

    const updateList = {
        Disc: true,
        Polygon: true,
    }

    useEffect(() => {
        const canvas = canvasRef.current;
        const ctx = canvas.getContext("2d");
        ctx.clearRect(0, 0, width, height);
        change({...Request})
    }, [Request]);

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