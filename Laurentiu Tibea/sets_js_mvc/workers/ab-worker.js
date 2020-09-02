onmessage = e => {
    if(e.data === "stop");
    else{
        const data = e.data.split(" ");
        const a = data[0].split(",").map(item => parseInt(item,10));
        const b = data[1].split(",").map(item => parseInt(item,10));
        const ab = [];
        for (let i=0; i<a.length; i++) {
            if (b.indexOf(a[i]) === -1) {
              ab.push(a[i]);
            }
        }
        const set = [...new Set([...ab])];
        postMessage(set.toString());
    }
}