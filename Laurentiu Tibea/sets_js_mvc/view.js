class view{
    _events;
	canvas;
    context = [];
    set1;
    set2;

	constructor(){
        document.getElementById("start").disabled = false;
        document.getElementById("stop").disabled = true;
        
        document.getElementById("start").addEventListener("click", this.start.bind(this));
		document.getElementById("stop").addEventListener("click", this.stop.bind(this));

        document.getElementById("start_intersection").addEventListener("click", this.start_single.bind(this,0,"intersection"));
        document.getElementById("start_union").addEventListener("click", this.start_single.bind(this,1,"union"));
        document.getElementById("start_ab").addEventListener("click", this.start_single.bind(this,2,"ab"));
        document.getElementById("start_ba").addEventListener("click", this.start_single.bind(this,3,"ba"));

        document.getElementById("request").addEventListener("click", this.initRequestWorkers.bind(this));

        this.canvas = document.getElementsByClassName("canvas");
        this.context = new Array(this.canvas.length);
        for(let i=0; i<this.canvas.length; i++) this.context[i] = this.canvas[i].getContext("2d");
        
        this.initRequestWorkers();
    }

    initRequestWorkers(){
        this.set1 = this.requestWorker("set1");
        this.set2 = this.requestWorker("set2");
    }
    
    requestWorker(set){
        const numberOfItems = document.getElementById("length").value.toString();
        const setMaxValue = document.getElementById("max_val").value.toString();
        const reqWorker = new Worker("workers/request-worker.js");
        reqWorker.onmessage = e => {
            const {array} = e.data;
            document.getElementById(set).value = array;
        }
        reqWorker.postMessage(`${numberOfItems} ${setMaxValue}`);
    }

	start(){
        document.getElementById("start").disabled = true;
        document.getElementById("stop").disabled = false;
        document.getElementById("start_intersection").disabled = true;
        document.getElementById("start_union").disabled = true;
        document.getElementById("start_ab").disabled = true;
        document.getElementById("start_ba").disabled = true;
        document.getElementById("result_container").style.display = "flex";
        this.set1 = document.getElementById("set1").value;
        this.set2 = document.getElementById("set2").value;
        const textareas = document.getElementsByClassName("text_area");
        for(let i=0; i<textareas.length; i++) textareas[i].style.display = "none";
		this._events.emit("start_clicked",{set1:this.set1, set2:this.set2});
    }

    start_single(textarea_index, target_name){
        document.getElementById("start").disabled = true;
        document.getElementById(`start_${target_name}`).disabled = true;
        document.getElementById("result_container").style.display = "flex";
        this.set1 = document.getElementById("set1").value;
        this.set2 = document.getElementById("set2").value;
        const textareas = document.getElementsByClassName("text_area");
        textareas[textarea_index].style.display = "none";
		this._events.emit("start_single_clicked",{set1:this.set1, set2:this.set2, target:textarea_index, target_name:target_name});
    }
    
    stop(){
        document.getElementById("stop").disabled = true;
        const textareas = document.getElementsByClassName("text_area");
        for(let i=0; i<textareas.length; i++) setTimeout(() => textareas[i].value = "", 2000);
        document.getElementById("result_container").style.display = "none";
        setTimeout(() => {
            document.getElementById("start").disabled = false;
            document.getElementById("start_intersection").disabled = false;
            document.getElementById("start_union").disabled = false;
            document.getElementById("start_ab").disabled = false;
            document.getElementById("start_ba").disabled = false;
        }, 2000);
		this._events.emit("stop_clicked");
    }

	set_events(events){
		this._events = events;
	}

	update_loading(data){
        this.canvas[data.index].style.display = "block";
		for(let i=0; i<this.canvas.length; i++){
            this.context[i].save();
            this.context[i].clearRect(0, 0, this.canvas[i].width, this.canvas[i].height);
            this.context[i].translate(this.canvas[i].width / 2, this.canvas[i].height / 2);
            this.context[i].rotate(Math.PI * 2 * data.angle.value);
            for (var j = 0; j < 300; j++) {
                this.context[i].beginPath();
                this.context[i].rotate(Math.PI * 2 / 300);
                this.context[i].moveTo(this.canvas[i].width / 15, 0);
                this.context[i].lineTo(this.canvas[i].width / 7, 0);
                this.context[i].lineWidth = this.canvas[i].width / 30;
                this.context[i].strokeStyle = "rgba(0,0,0," + j / (300*10) + ")";
                this.context[i].stroke();
            }
            this.context[i].restore();
        }
    }
    
    update_loading_single(data){
        this.canvas[data.index].style.display = "block";
        this.context[data.index].save();
        this.context[data.index].clearRect(0, 0, this.canvas[data.index].width, this.canvas[data.index].height);
        this.context[data.index].translate(this.canvas[data.index].width / 2, this.canvas[data.index].height / 2);
        this.context[data.index].rotate(Math.PI * 2 * data.angle.value);
        for (var j = 0; j < 300; j++) {
            this.context[data.index].beginPath();
            this.context[data.index].rotate(Math.PI * 2 / 300);
            this.context[data.index].moveTo(this.canvas[data.index].width / 15, 0);
            this.context[data.index].lineTo(this.canvas[data.index].width / 7, 0);
            this.context[data.index].lineWidth = this.canvas[data.index].width / 30;
            this.context[data.index].strokeStyle = "rgba(0,0,0," + j / (300*10) + ")";
            this.context[data.index].stroke();
        }
        this.context[data.index].restore();
	}

	update_sets(data){
        document.getElementById("start").disabled = false;
        document.getElementById("stop").disabled = true;
        document.getElementById("start_intersection").disabled = false;
        document.getElementById("start_union").disabled = false;
        document.getElementById("start_ab").disabled = false;
        document.getElementById("start_ba").disabled = false;
        this.canvas[data.index].style.display = "none";
        document.getElementById([data.target]).style.display = "block";
        document.getElementById([data.target]).value = data.value;
        const results = document.getElementsByClassName("result");
    }
    
    update_single_sets(data){
        document.getElementById("start").disabled = false;
        document.getElementById("stop").disabled = true;
        document.getElementById(`start_${data.target}`).disabled = false;
        this.canvas[data.index].style.display = "none";
        document.getElementById([data.target]).style.display = "block";
        document.getElementById([data.target]).value = data.value;
        const results = document.getElementsByClassName("result");
    }
}