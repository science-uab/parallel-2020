var start = false;
var data_totala=(new Date()).valueOf();
var interval = null;

onmessage = function(e){
    var data = e.data.split(" ");
    if (data[0] == "stop"){
        start = false;
        clearInterval(interval)
	}
	else if (data[0] == "start"){
        start = true;
        data_totala += parseInt(data[1])*1000;
        data_totala += parseInt(data[2]*1000);
        timer();
    }
}

function timer(){
    if(start == true){
        interval = setInterval(function(){
            var data_noua=(new Date()).valueOf();
            var diferenta = data_totala-data_noua;
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