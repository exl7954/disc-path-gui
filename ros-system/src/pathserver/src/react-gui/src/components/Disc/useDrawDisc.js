import { useCanvas } from "../CanvasProvider";
import { useEffect } from "react";

export const useDrawDisc = ({ x, y, r }) => {
    const { draw } = useCanvas();

    useEffect(() => {
        draw((ctx) => {
            ctx.beginPath();
            ctx.arc(x, y, r, 0, 2 * Math.PI);
            ctx.fillStyle = "#C4E4FF";
            ctx.fill()
            ctx.stroke();
        })
    }, [x, y, r]);
}