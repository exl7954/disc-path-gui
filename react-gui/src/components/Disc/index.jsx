import {useDrawDisc} from "./useDrawDisc";

const Disc = (props) => {
    if (props.x == undefined || props.y == undefined || props.r == undefined) {
        return null;
    }
    useDrawDisc(props);
    return null;
}

export default Disc;