onmessage = e => {
    if(e.data === "stop");
    else{
        const data = e.data.split(" ");
        const a = data[0].split(",").map(item => parseInt(item,10));
        const b = data[1].split(",").map(item => parseInt(item,10));
        const ba = [];
        for (let i=0; i<b.length; i++) {
            if (a.indexOf(b[i]) === -1) {
              ba.push(b[i]);
            }
        }
        const set = [...new Set([...ba])];
        postMessage(set.toString());
    }
}