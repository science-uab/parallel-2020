class t_model{
	angle;
    _worker1;
    _worker2;
    _worker3;
	_events;
    id_timer;

	constructor(){
		this.angle = {value:1};
        this._worker1 = null;
        this._worker2 = null;
        this._worker3 = null;
        this.id_timer = null;
	}

	set_events(events){
		this._events = events;
	}

	start(){
		if (this._worker1 == null){
			this._worker1 = new Worker("worker1.js");
			const _events_bk = this._events;
			this._worker1.onmessage = function(e){
                _events_bk.emit("draw_1",e.data);
                console.log(e);
			}
		}
		else this._worker1.postMessage("start");
    
        if (this._worker2 == null){
			this._worker2 = new Worker("worker2.js");
			const _events_bk = this._events;
			this._worker2.onmessage = function(e){
                _events_bk.emit("draw_3",e.data);
                console.log(e);
			}
		}
        else this._worker2.postMessage("start");
        
        if (this._worker3 == null){
			this._worker3 = new Worker("worker3.js");
			const _events_bk = this._events;
			this._worker3.onmessage = function(e){
                _events_bk.emit("draw_5",e.data);
                console.log(e);
			}
		}
		else this._worker3.postMessage("start");

        this.id_timer = setInterval(this.start_draw.bind(this), 1000);
	}

	start_draw(){
        // this._events.emit("draw_1", this.angle);
        // this._events.emit("draw_2", this.angle);
        // this._events.emit("draw_3", this.angle);
        // this._events.emit("draw_4", this.angle);
        // this._events.emit("draw_5", this.angle);
        // this._events.emit("draw_6", this.angle);
        this._events.emit("on_1_finished", "The construction of face 2 started." + this.angle.value + " seconds ago.");
        this._events.emit("on_3_finished", "The construction of face 4 started." + this.angle.value + " seconds ago.");
        this._events.emit("on_5_finished", "The construction of face 6 started." + this.angle.value + " seconds ago.");
        
        console.log(this.angle);
        this.angle.value++;
    }
    

	stop(){
		clearInterval(this.id_timer);
        this._worker1.postMessage("stop");
        this._worker2.postMessage("stop");
        this._worker3.postMessage("stop");
	}
}