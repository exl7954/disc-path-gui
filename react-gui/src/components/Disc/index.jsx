import { useCanvas } from "../CanvasProvider";

const Disc = (props) => {
    const { draw } = useCanvas();
    
    if (props.x !== undefined && props.y !== undefined && props.r !== undefined) {
        draw((ctx) => {
            ctx.beginPath();
            ctx.arc(props.x, props.y, props.r, 0, 2 * Math.PI);
            ctx.fillStyle = props.color;
            ctx.fill();
            ctx.stroke();
        })
    }

    return null;
}

export default Disc;