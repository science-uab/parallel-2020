class t_view{
	_events;
    canvas1;
    canvas2;
    canvas3;
    canvas4;
    canvas5;
    canvas6;
    context1;
    context2;
    context3;
    context4;
    context5;
    context6;

	constructor(){
		document.getElementById("id_stop_button").disabled = true;
		document.getElementById("id_start_button").disabled = false;

		document.getElementById("id_start_button").addEventListener("click", this.start.bind(this));
		document.getElementById("id_stop_button").addEventListener("click", this.stop.bind(this));

		this.canvas1 = document.getElementById("id_canvas1");
        this.context1 = this.canvas1.getContext("2d");
        this.canvas2 = document.getElementById("id_canvas2");
        this.context2 = this.canvas2.getContext("2d");
        this.canvas3= document.getElementById("id_canvas3");
        this.context3 = this.canvas3.getContext("2d");
        this.canvas4= document.getElementById("id_canvas4");
        this.context4 = this.canvas4.getContext("2d");
        this.canvas5= document.getElementById("id_canvas5");
        this.context5 = this.canvas5.getContext("2d");
        this.canvas6 = document.getElementById("id_canvas6");
        this.context6 = this.canvas6.getContext("2d");
	}

	start(){
		document.getElementById("id_start_button").disabled = true;
		document.getElementById("id_stop_button").disabled = false;
		this._events.emit("start_clicked_uab");
	}

	stop(){
		document.getElementById("id_start_button").disabled = false;
		document.getElementById("id_stop_button").disabled = true;
		this._events.emit("stop_clicked_uab");
	}

	set_events(events){
		this._events = events;
    }
    
    draw_1() { 
        this.context1.clearRect(0, 0, this.canvas1.width, this.canvas1.height);
        this.context1.beginPath();
        setTimeout(() => {
            this.context1.moveTo(400, 400);
            this.context1.lineTo(600, 400); 
            this.context1.stroke();
        }, 0);

        setTimeout(() => {
            this.context1.moveTo(600, 400);
            this.context1.lineTo(600, 600); 
            this.context1.stroke();
        },1500);

        setTimeout(() => {
            this.context1.moveTo(600,600);
            this.context1.lineTo(400,600);
            this.context1.stroke();
        },3000);
        
        setTimeout(() => {
            this.context1.moveTo(400,600);
            this.context1.lineTo(400,400);
            this.context1.stroke();
        },4500);
    }

    draw_2() {
        this.context2.clearRect(0, 0, this.canvas2.width, this.canvas2.height);
        this.context2.strokeStyle = 'red';
        this.context2.beginPath();

        setTimeout(() => {
            this.context2.moveTo(400, 400);
            this.context2.lineTo(500, 350); 
            this.context2.stroke();
        },0);

        setTimeout(() => {
            this.context2.moveTo(500,350);
            this.context2.lineTo(700,350);
            this.context2.stroke();
        },1500);

        setTimeout(() => {
            this.context2.moveTo(700,350);
            this.context2.lineTo(600,400);
            this.context2.stroke();
        },3000);

        setTimeout(() => {
            this.context2.moveTo(600,400);
            this.context2.lineTo(400,400);
            this.context2.stroke();
        },4500);

    }

    draw_3 () { 
        this.context3.clearRect(0, 0, this.canvas3.width, this.canvas3.height);
        this.context3.strokeStyle = 'green';
        this.context3.beginPath();


        setTimeout(() => {
            this.context3.moveTo(700,350);
            this.context3.lineTo(700,550);
            this.context3.stroke();
        },0);
        
        setTimeout(() => {
            this.context3.moveTo(700,550);
            this.context3.lineTo(600,600);
            this.context3.stroke();
        },1500);

        setTimeout(() => {
            this.context3.moveTo(600,600);
            this.context3.lineTo(600,400);
            this.context3.stroke();
        },3000);
    }

    draw_4() {
        this.context4.clearRect(0, 0, this.canvas4.width, this.canvas4.height);
        this.context4.strokeStyle = 'orange';
        this.context4.beginPath();

        setTimeout(() => {
            this.context4.moveTo(600,600);
            this.context4.lineTo(700,550);
            this.context4.stroke();
        },0);

        setTimeout(() => {
            this.context4.moveTo(700,550);
            this.context4.lineTo(500,550);
            this.context4.stroke();
        },1500);

        setTimeout(() => {
            this.context4.moveTo(500,550);
            this.context4.lineTo(400,600);
            this.context4.stroke();
        },3000);

        setTimeout(() => {
            this.context4.moveTo(400,600);
            this.context4.lineTo(600,600);
            this.context4.stroke();
        },4500);
    }

    draw_5() {
        this.context5.clearRect(0, 0, this.canvas5.width, this.canvas5.height);
        this.context5.strokeStyle = 'pink';
        this.context5.beginPath();

        
        setTimeout(() => {
            this.context5.moveTo(500,350);
            this.context5.lineTo(500,550);
            this.context5.stroke();
        },0);
        setTimeout(() => {
            this.context5.moveTo(500,550);
            this.context5.lineTo(400,600);
            this.context5.stroke();
        },1500);

        setTimeout(() => {
            this.context5.moveTo(400,600);
            this.context5.lineTo(400,400);
            this.context5.stroke();
        },3000);
        setTimeout(() => {
            this.context5.moveTo(400,400);
            this.context5.lineTo(500,350);
            this.context5.stroke();
        },4500);
    }

	draw_6(angle){
        this.context6.clearRect(0, 0, this.canvas6.width, this.canvas6.height);
        this.context6.strokeStyle = 'purple';
        this.context6.beginPath();

        setTimeout(() => {
            this.context6.moveTo(500,350);
            this.context6.lineTo(500,550);
            this.context6.stroke();
        },0);
        setTimeout(() => {
            this.context6.moveTo(500,550);
            this.context6.lineTo(700,550);
            this.context6.stroke();
        },1500);

        setTimeout(() => {
            this.context6.moveTo(700,550);
            this.context6.lineTo(700,350);
            this.context6.stroke();
        },3000);
        setTimeout(() => {
            this.context6.moveTo(700,350);
            this.context6.lineTo(500,350);
            this.context6.stroke();
        },4500);
	}

    msg1(msg) {
        document.getElementById("id1").innerHTML = msg;
    }
    msg3(msg) {
        document.getElementById("id2").innerHTML = msg;
    }
    msg5(msg) {
        document.getElementById("id3").innerHTML = msg;
    }
}