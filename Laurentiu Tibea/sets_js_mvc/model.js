class model{
    angle;
	workers;
	_events;
    timers;
    set1;
    set2;
    results_id;
    workers_scripts;
    single_workers;
    single_timer;
    
    constructor(){
        this.angle = {value:0};
        this.results_id = ["intersection","union","ab","ba"];
        this.workers_scripts = ["workers/intersection-worker.js","workers/union-worker.js","workers/ab-worker.js","workers/ba-worker.js"];
		this.workers = null;
        this.timers = new Array(4);
        this.single_workers = new Array(4);
        this.single_timer = null;
	}

	set_events(events){
		this._events = events;
    }

	start(data){
        this.set1 = data.set1;
        this.set2 = data.set2;
		if (this.workers == null){
            this.workers = new Array(4);
			const _events_bk = this._events;
            for(let i=0; i<4; i++){
                this.workers[i] = new Worker(this.workers_scripts[i]);
                this.workers[i].onmessage = e => {
                    setTimeout(() => {
                        clearInterval(this.timers[i]);
                        _events_bk.emit("sets_computed", {value: e.data, target: this.results_id[i], index: i});
                    },2000)
                }
                this.workers[i].postMessage(`${this.set1} ${this.set2}`);
            }
		}
		else for(let i=0; i<4; i++) this.workers[i].postMessage(`${this.set1} ${this.set2}`);
	
		for(let i=0; i<4; i++) this.timers[i] = setInterval(this.draw_loading.bind(this,i), 50);
    }
    
    stop(){
        for(let i=0; i<4; i++){
            clearInterval(this.timers[i]);
            this.workers[i].postMessage("stop");
        }
    }

    start_single(data){
        this.set1 = data.set1;
        this.set2 = data.set2;
		if (this.single_workers[data.target] == null){
            this.single_workers[data.target] = new Worker(this.workers_scripts[data.target]);
			const _events_bk = this._events;
            this.single_workers[data.target].onmessage = e => {
                setTimeout(() => {
                    clearInterval(this.single_timer);
                    _events_bk.emit("sets_single_computed", {value: e.data, target: this.results_id[data.target], index: data.target});
                    this.single_workers[data.target] = null;
                },2000)
            }
            this.single_workers[data.target].postMessage(`${this.set1} ${this.set2}`);
		}
		else this.single_workers[data.target].postMessage(`${this.set1} ${this.set2}`);
	
		this.single_timer = setInterval(this.draw_loading_single.bind(this,data.target), 50);
    }

	draw_loading(index){
		this._events.emit("angle_updated", {angle:this.angle, index: index});
		this.angle.value += 0.01;
    }
    
    draw_loading_single(index){
		this._events.emit("angle_updated_single", {angle:this.angle, index: index});
		this.angle.value += 0.01;
	}
}