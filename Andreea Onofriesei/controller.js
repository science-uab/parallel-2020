class t_controller{
	view;
	model;

	constructor(view, model){
		const events_list_view = new t_list_of_events();
		events_list_view.subscribe("start_clicked_uab", this.on_start.bind(this));
		events_list_view.subscribe("stop_clicked_uab", this.on_stop.bind(this));
		
        const events_list_model = new t_list_of_events();
        
        events_list_model.subscribe("draw_1", this.on_draw_1.bind(this));
        events_list_model.subscribe("draw_2", this.on_draw_2.bind(this));
        events_list_model.subscribe("draw_3", this.on_draw_3.bind(this));
        events_list_model.subscribe("draw_4", this.on_draw_4.bind(this));
        events_list_model.subscribe("draw_5", this.on_draw_5.bind(this));
        events_list_model.subscribe("draw_6", this.on_draw_6.bind(this));
        events_list_model.subscribe("on_1_finished", this.on_1_finished.bind(this));
        events_list_model.subscribe("on_3_finished", this.on_3_finished.bind(this));
        events_list_model.subscribe("on_5_finished", this.on_5_finished.bind(this));
        
        events_list_model.subscribe("stop_clicked_uab", this.on_stop.bind(this));

		this.view = view;
		this.view.set_events(events_list_view);
		this.model = model;
		this.model.set_events(events_list_model);
	}
	
	on_start(){
		this.model.start();
	}
	
	on_stop(){
		this.model.stop();
	}

	on_draw_1(angle){
		this.view.draw_1(angle);
    }

    on_1_finished(msg,angle) {
        this.view.msg1(msg);
        this.view.draw_2(angle);
    }

    on_draw_2(angle){
		this.view.draw_2(angle);
    }

    on_3_finished(msg,angle) {
        this.view.msg3(msg);
        this.view.draw_4(angle);
    }

    on_5_finished(msg,angle) {
        this.view.msg5(msg);
        this.view.draw_6(angle);
    }

    on_draw_3(angle){
		this.view.draw_3(angle);
    }
    on_draw_4(angle){
		this.view.draw_4(angle);
    }
    on_draw_5(angle){
		this.view.draw_5(angle);
    }
    on_draw_6(angle){
		this.view.draw_6(angle);
    }

}

const app = new t_controller(new t_view(), new t_model());