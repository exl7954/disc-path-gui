import { useCanvas } from "../CanvasProvider";
import { useEffect } from "react";

export const useDrawPolygon = ({ color, points }) => {
    const { draw } = useCanvas();

    useEffect(() => {
        draw((ctx) => {
            ctx.fillStyle = color;
            ctx.beginPath();
            points.forEach(([x, y], index) => {
                if (index === 0) {
                    ctx.moveTo(x, y);
                }
                else {
                    ctx.lineTo(x, y);
                }
            });
            ctx.closePath();
            ctx.fill();
        });
    }, [color, points, draw]);
};