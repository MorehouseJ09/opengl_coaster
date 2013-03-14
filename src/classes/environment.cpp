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

		glBegin(GL_POLYGON);	

			glColor3f(0, 1.0, 0.0);
			glVertex3f(-50, 0, 0);
			glVertex3f(50, 0, 0);
			glVertex3f(50, 50, 0);
			glVertex3f(-50, 50, 0);

		glEnd();
	}

	void Environment::drawSky() {

		printf("HELLO FROM SKY ELEMENT\n");
			
	}
}