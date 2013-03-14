#include "modules/application.hpp"

namespace application {

	void init() {

		//glut initialization data goes here
		// anything that needs to be initialized in the main loop can be inserted here to help offset application load
	}

	// implement idle function -- responsible for working with the image on a consistent basis to continually ensure its integrity
	void idle() {

		// initialize other idle functionality here -- this could be a casual rotation or some sort of randomization of the translations etc
		glutPostRedisplay();//run the display segment again to update any changes that we may have
	}

	// display is for drawing out the elements using our scaled frame etc
	void display() {

		// rotate, scaling and translation should take place before this code in the future
		// draw a quick cube around the origin of the screen
		glViewport(0,0, 600, 600);	

		// start editing the modelview -- not the scenary
		glMatrixMode(GL_MODELVIEW);

			glLoadIdentity();

			// reset the matrix to a default state before rotating scaling etc
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
			// clear the colors and make the background black
			glClearColor(0.0, 0.0, 0.0, 1.0);

			// reset the rotation of all axes to 0,0,0
			glTranslatef(state->getTranslation(0), state->getTranslation(1), state->getTranslation(2));

			// set up the proper scale each time!
			glScalef(state->getScale(0), state->getScale(1), state->getScale(2));

			(*controller)();//call controller function
			
		// initialize the gl_projection matrix -- this is useful for setting up perspective etc ...
		// initialize our matrix for the final viewing using projection ... 
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// fov angle, aspect ratio = width / height, near z, far z
		gluPerspective(10.0f, windowWidth / windowHeight, 0.01, 1000.0);

		// swap the buffers and bring the second one out from hiding
		glutSwapBuffers();

		// check if we need to run the screenshot program etc
		// image::screenshotController();//run the controller
	}

}
