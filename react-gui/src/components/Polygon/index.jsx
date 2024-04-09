import { useCanvas } from "../CanvasProvider";

const Polygon = (props) => {
    const { draw } = useCanvas();

    draw((ctx) => {
        ctx.fillStyle = props.color;
        ctx.beginPath();
        props.points.forEach(([x, y], index) => {
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

    return null;
}

export default Polygon;