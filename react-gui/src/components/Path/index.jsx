import { useCanvas } from "../CanvasProvider";

const Path = (props) => {
    const { draw } = useCanvas();

    if (props.response.path != undefined && props.response.response == "true") {
        draw((ctx) => {
            let points = props.response.path;
            let path = points.split('|')
                .map((x) => x.trim())
                .filter((arr) => arr.length > 1)
                .map(p => p.split(' '))
                .map(p => p.map((x) => parseInt(x)));
            ctx.strokeStyle = "purple";
            ctx.beginPath();
            ctx.moveTo(path[0][0], path[0][1]);
            for (let i = 1; i < path.length; i++) {
                ctx.lineTo(path[i][0], path[i][1]);
            }
            ctx.stroke();
        })
    }
    return null;
}

export default Path;