import { useCanvasLower } from '../CanvasProvider';

const Rectangle = (props) => {
    const { drawLower } = useCanvasLower();

    drawLower((ctx) => {
        ctx.beginPath();
        ctx.strokeStyle = "black";
        ctx.fillStyle = props.color;
        ctx.rect(props.x - props.width / 2, props.y - props.height / 2, props.width, props.height);
        ctx.fill();
        ctx.stroke();
    })

    return null;
}

export default Rectangle;