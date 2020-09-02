var worker_cronometru = null;
var worker_timer = null;

function startCronometru(){
    document.getElementById("startCronometru").disabled = true;
    document.getElementById("stopCronometru").disabled = false;
    var comparare_cronometru = [];
    var minute_cronometru = document.getElementById("input_cronometru_minute").value;
    var secunde_cronometru = document.getElementById("input_cronometru_secunde").value;
    minute_cronometru = minute_cronometru.toString();
    if (minute_cronometru.length == 1) minute_cronometru = "0"+minute_cronometru;
    secunde_cronometru = secunde_cronometru.toString();
    if (secunde_cronometru.length == 1) secunde_cronometru = "0"+secunde_cronometru;
    worker_cronometru = new Worker("cronometru.js");
    worker_cronometru.onmessage = function(e){
        comparare_cronometru = e.data.split(":");
        if(comparare_cronometru[0] == minute_cronometru && comparare_cronometru[1] == secunde_cronometru){
            worker_cronometru.postMessage("stop");
            document.getElementById("startCronometru").disabled = false;
            document.getElementById("stopCronometru").disabled = true;
        }
        document.getElementById("cronometru").innerHTML = e.data;
    }
    worker_cronometru.postMessage("start");
}

function stopCronometru(){
    worker_cronometru.postMessage("stop");
    document.getElementById("startCronometru").disabled = false;
    document.getElementById("stopCronometru").disabled = true;
}

function startTimer(){
    document.getElementById("startTimer").disabled = true;
    document.getElementById("stopTimer").disabled = false;
    var comparare_timer = [];
    var minute_timer = document.getElementById("input_timer_minute").value;
    var secunde_timer = document.getElementById("input_timer_secunde").value;
    minute_timer = minute_timer.toString();
    if (minute_timer.length == 1) minute_timer = "0"+minute_timer;
    secunde_timer = secunde_timer.toString();
    if (secunde_timer.length == 1) secunde_timer = "0"+secunde_timer;
    document.getElementById("timer").innerHTML = minute_timer+":"+secunde_timer;
    worker_timer = new Worker("timer.js");
    worker_timer.onmessage = function(e){
        comparare_timer = e.data.split(":");
        if(comparare_timer[0] == "00" && comparare_timer[1] == "00") {
            worker_timer.postMessage("stop");
            document.getElementById("startTimer").disabled = false;
            document.getElementById("stopTimer").disabled = true;
        }
        document.getElementById("timer").innerHTML = e.data;
    }
    worker_timer.postMessage("start "+minute_timer+" "+secunde_timer);
}

function stopTimer(){
    worker_timer.postMessage("stop");
    document.getElementById("startTimer").disabled = false;
    document.getElementById("stopTimer").disabled = true;
}