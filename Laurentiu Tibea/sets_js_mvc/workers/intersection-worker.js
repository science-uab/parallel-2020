onmessage = e => {
    if(e.data === "stop");
    else{
        const data = e.data.split(" ");
        const a = data[0].split(",").map(item => parseInt(item,10));
        const b = data[1].split(",").map(item => parseInt(item,10));
        let intersection = [];
        for(let i=0; i<a.length; i++){
            for(let j=0; j<b.length; j++){
                if(a[i] === b[j]) intersection.push(a[i]);
            }
        }
        intersection = intersection.sort((a,b) => a-b);
        const set = [...new Set([...intersection])];
        postMessage(set.toString());
    }
}