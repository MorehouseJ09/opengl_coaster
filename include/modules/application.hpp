#ifndef APPLICATION_HPP
#define APPLICATION_HPP

// initialize our other namespace functions for heightfield data and the display methods that will actually display our imagery
#include "classes/states.hpp"
#include "modules/image.hpp"
#include "modules/display.hpp"

// initialize standard libraries needed if they were not already included
#include <stdlib.h>
#include <math.h>

// gl libraries
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

// grab a copy of the main.cpp - declared state class that is global
extern application::State * state;
extern application::Controller * controller;

// 
namespace application {

	// initialize the entire function / functionality etc
	// initialize image and basics of the application here
	void init();	

	// called repeatedly
	// idle function called when nothing happening on machine
	void idle();

	// display is what is shown each time
	void display();

}

#endif 	