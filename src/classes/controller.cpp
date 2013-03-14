#include "classes/controller.hpp"

// include project libraries
#include "classes/track.hpp"
#include "classes/environment.hpp"

// set up the proper namespaces for this cpp file to use
using namespace track;
using namespace environment;

namespace application {

	Controller::Controller(std::vector<Spline> * splines, State * state) : splines(splines), state(state) {

		// initialize the splines so that they are stored as members 	
		this->track = new Track(this->splines);
		this->environment = new Environment();//create a new environment for the controller to draw out behind the element
	}	


	Controller::~Controller() {

	}

	void Controller::operator() () {

		// this is supposed to be call on each redraw element
		if (this->state->getApplicationMode() == application::NORMAL)

			this->drawStatic();

		else this->drawRide();
		
	}

	void Controller::drawStatic() {

		// responsible for drawing the element as needed in the static view as well as setting up the project ion viewing
		
	}	

	void Controller::drawRide() {

		
		
	}


};