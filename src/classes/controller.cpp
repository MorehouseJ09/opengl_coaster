#include "classes/controller.hpp"



namespace application {

	Controller::Controller(std::vector<Spline> * splines, State * state) : splines(splines), state(state) {

		// initialize the splines so that they are stored as members 	
		this->track = new Track(this->splines);
	}	


	Controller::~Controller() {

	}

	void Controller::operator() () {

		// this is supposed to be call on each redraw element
			
		this->track->draw();
	}

	void Controller::drawStatic() {

		

	}	

	void Controller::drawRide() {

		
		
	}


};