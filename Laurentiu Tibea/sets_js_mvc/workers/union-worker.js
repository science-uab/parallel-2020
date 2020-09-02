onmessage = e => {
    if(e.data === "stop");
    else{
        const data = e.data.split(" ");
        const a = data[0].split(",").map(item => parseInt(item,10));
        const b = data[1].split(",").map(item => parseInt(item,10));
        const union = [...new Set([...a, ...b])].sort((a,b) => a-b);
        postMessage(union.toString());
    }
}