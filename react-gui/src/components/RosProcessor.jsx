import React from "react";

export function RosProcessor(props) {
    const BOX_COLORS = { 0: "green", 1: "red", 2: "yellow", 3: "grey" };
    let ros = new ROSLIB.Ros({
        url: 'ws://localhost:9090'
    });
    ros.on('connection', function () {
        console.log('Connected to websocket server.');
    });
    ros.on('error', function (error) {
        console.log('Error connecting to websocket server: ', error);
    });
    ros.on('close', function () {
        console.log('Connection to websocket server closed.');
    });

    let client = new ROSLIB.Service({
        ros: ros,
        name: '/find_path',
        serviceType: 'interfaces/srv/FindPath'
    });

    let request = new ROSLIB.ServiceRequest({
        alpha: [40, 360],
        bta: [460, 100],
        epsilon: 1,
        boxwidth: 512,
        boxheight: 512,
        r0: 30,
        qtype: 0,
        seed: 111,
        deltax: 0,
        deltay: 0,
        scale: 1,
        numpts: 12,
        pts: "10,502|110,502|110,402|10,402|200,312|250,332|300,292|210,162|220,202|50,112|100,162|150,92",
        numpolygons: 3,
        polygons: "1,4,3,2,1|5,9,8,7,6,5|10,12,11,10"
    });

    let processess = () => client.callService(request, (result) => {
        props.func(result);
    })

    return(
        <button onClick={processess}>Processess</button>
    )
};