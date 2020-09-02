class controller{
    view;
    model;

    constructor(view,model){
        const events_list_view = new list_of_events();
        events_list_view.subscribe("start_clicked", this.on_start.bind(this));
		events_list_view.subscribe("stop_clicked", this.on_stop.bind(this));

        events_list_view.subscribe("start_single_clicked", this.on_start_single.bind(this));
		
		const events_list_model = new list_of_events();
		events_list_model.subscribe("sets_computed", this.on_sets_computed.bind(this));
		events_list_model.subscribe("angle_updated", this.on_angle_updated.bind(this));
		
		events_list_model.subscribe("sets_single_computed", this.on_sets_single_computed.bind(this));
		events_list_model.subscribe("angle_updated_single", this.on_angle_updated_single.bind(this));

		this.view = view;
		this.view.set_events(events_list_view);
		this.model = model;
		this.model.set_events(events_list_model);
    }

    on_start(data){
		this.model.start(data);
    }
	
	on_start_single(data){
		this.model.start_single(data);
    }
    
    on_stop(){
        this.model.stop();
	}
	
	on_sets_computed(data){
		this.view.update_sets(data);
	}

	on_sets_single_computed(data){
		this.view.update_single_sets(data);
	}
	
	on_angle_updated(angle){
		this.view.update_loading(angle);
	}

	on_angle_updated_single(angle){
		this.view.update_loading_single(angle);
	}
}

const app = new controller(new view(), new model());