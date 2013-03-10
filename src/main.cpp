#include "classes/state.hpp"
// #include "modules/image.hpp" //useful for user interaction etc
// #include "modules/interaction.hpp" //responsible for handling user interaction
// #include "modules/display.hpp" //responsible for drawing out the actual map elements

// include application code base / namespaces
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <pic.h>

// initialize a global state object
// keep this in memory for speed
application::State state;//this is the global state object 








// initialize main functionality etc
int main (int argc, char ** argv) {

  // set up the initializer function for glut
  glutInit(&argc, argv);

  // initialize double buffer element
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

  // set up the window size 
  glutInitWindowSize(state.getScreenWidth(), state.getScreenHeight());

  // set the window position
  // could initialize this later to have the state class get the full screen or something?
  glutInitWindowPosition(100, 100);

  // name the window etc ... 
  glutCreateWindow("Image Height Field");

  // set up the main display function
  // glutDisplayFunc(application::display);

  // set the various callbacks for the interaction with opengl
  // glutIdleFunc(application::idle);
  // glutSpecialFunc(interaction::keyPress);//enable the keypress handling

  // enable our mouse drag function for controlling the heightfield image
  // glutMotionFunc(interaction::mousedrag);
  // glutPassiveMotionFunc(interaction::mouseidle);
  // glutMouseFunc(interaction::mousebutton);

  // enable 3d buffering / z-buffer
  // glEnable(GL_DEPTH_TEST);
  // enable point size for this particular program
  // glEnable(GL_PROGRAM_POINT_SIZE);

  // going to assume that we are using the default reshape function
  // just need our viewport set to 0,0,w,h
  // now enter the main glut loop 
  // glutMainLoop();
}