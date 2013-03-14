#include "classes/environment.hpp"

namespace environment {

	Environment::Environment() {
		
			
			

	}

	Environment::~Environment() {




	}

	void Environment::operator() () {

		this->drawGround();//draw the basic ground structure
		this->drawSky();//draw the sky etc structure

	}

	void Environment::drawGround() {

		printf("HELLO FROM GROUND SECTION");


	}

	void Environment::drawSky() {

		printf("HELLO FROM SKY ELEMENT");
			
	}
}