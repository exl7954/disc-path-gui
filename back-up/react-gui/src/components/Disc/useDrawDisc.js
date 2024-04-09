import { useCanvas } from "../CanvasProvider";
import { useEffect } from "react";

export const useDrawDisc = ({ x, y, r, color, trigger }) => {
    const { draw } = useCanvas();
    useEffect(() => {
        if (x !== undefined && y !== undefined && r !== undefined) {
            draw((ctx) => {
                ctx.beginPath();
                ctx.arc(x, y, r, 0, 2 * Math.PI);
                ctx.fillStyle = color;
                ctx.fill();
                ctx.stroke();
            })
        }
    }, [x, y, r, trigger]);
}