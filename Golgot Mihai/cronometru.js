var start = false;
var data_curenta=(new Date()).valueOf();
var interval = null;

onmessage = function(e){
    if (e.data == "stop"){
        start = false;
        clearInterval(interval)
	}
	else if (e.data == "start"){
        start = true;
        cronometru();
    }
}

function cronometru(){
    if(start == true){
        interval = setInterval(function(){
            var data_noua=(new Date()).valueOf();
            var diferenta = data_noua-data_curenta;
            var minute = Math.floor(diferenta/1000/60);
            var secunde = Math.floor(diferenta/1000)-minute*60;
            minute = minute.toString();
            if (minute.length == 1) minute = "0"+minute;
            secunde = secunde.toString();
            if (secunde.length == 1) secunde = "0"+secunde;
            postMessage(minute+":"+secunde);
        },100)
        start = false;
    }
}