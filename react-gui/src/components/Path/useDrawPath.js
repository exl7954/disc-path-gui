import { useCanvas } from "../CanvasProvider";
import { useEffect } from "react";

export const useDrawPath = ({ points, trigger }) => {
    const { draw } = useCanvas();

    useEffect(() => {
        draw((ctx) => {
            let path = points.split('|')
                .map((x) => x.trim())
                .filter((arr) => arr.length > 1)
                .map(p => p.split(' '))
                .map(p => p.map((x) => parseInt(x)));
            ctx.beginPath();
            ctx.moveTo(path[0][0], path[0][1]);
            for (let i = 1; i < path.length; i++) {
                ctx.lineTo(path[i][0], path[i][1]);
            }
            ctx.stroke();
        })
    }, [points, trigger]);
}