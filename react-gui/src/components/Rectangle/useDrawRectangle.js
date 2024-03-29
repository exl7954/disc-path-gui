import { useCanvas } from "../CanvasProvider";
import { useEffect } from "react";

export const useDrawRectangle = ({ color, x, y, width, height }) => {
    const { draw } = useCanvas();

    useEffect(() => {
        draw((ctx) => {
            ctx.beginPath();
            ctx.fillStyle = color;
            ctx.rect(x - width / 2, y - height / 2, width, height);
            ctx.fill();
            ctx.stroke();
        })
    }, [color, x, y, width, height, draw]);
}