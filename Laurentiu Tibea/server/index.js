const express = require("express");
const app = express();
const port = 5600;
const cors = require("cors");
const bodyParser = require("body-parser");

app.use(cors({
    origin: "*",
    methods: ["GET","PUT","POST","DELETE","PATCH","OPTIONS"],
    exposedHeaders: ["X-Total-Count", "Content-Range"]
}));

app.use(bodyParser.json());

app.use(bodyParser.urlencoded({ 
    extended: false 
}));

app.post("/", (req, res) => {
    const setLength = parseInt(req.body.setLength,10);
    const setMaxValue = parseInt(req.body.setMaxValue,10)+1;
    const array = Array.from({length: setLength}, () => {
        return Math.floor(Math.random() * setMaxValue);
    }).toString();
    res.status(200).send({array});
})

app.listen(port, () => console.log(`Server listening on port ${port}!`));