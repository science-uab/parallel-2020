var stopped = false;
//-------------------------------------------
onmessage = function(e){
	if (e.data == "stop"){
		stopped = true;
	}
	else
		if (e.data == "start"){
			stopped = false;
		}
}

function is_finished()
{
	if (stopped)
		;
	else{
        postMessage("draw_6");
           setTimeout(() => {
            postMessage("on_5_finished");
           },4500); 
        
    }
}

is_finished();