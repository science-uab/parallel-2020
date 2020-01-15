onmessage = e => {
    const dataSplit = e.data.split(" ");
    const data = {
        setLength: dataSplit[0],
        setMaxValue: dataSplit[1]
    }
    fetch("http://localhost:5600", {
        method: "POST",
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    })
    .then(res => res.json())
    .then(data => postMessage(data));
}