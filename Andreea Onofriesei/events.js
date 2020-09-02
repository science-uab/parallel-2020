class t_list_of_events{//Publisher/Subscriber pattern
	_events = [];
	constructor()
	{
	}
	
	subscribe(event_name, listener){
		if (this._events.length == 0){
			this._events.push(event_name);
			this._events[event_name] = [];
		}
		else{
			if (this._events.indexOf(event_name) == -1){
				this._events.push(event_name);
				this._events[event_name] = [];
			}
		}
		this._events[event_name].push(listener);
	}
	
	emit(event_name, args){
		this._events[event_name].forEach(func => func(args));
	}
}