#pragma once
/*
	We want to have this controller class control the various splines for different pieces of the controller
	We will make sure that before hand, the splines line up properly based on the entrance / exit segments etc
	Then we will have a hash table of different elements which will each be their own instance of objects that inherit the basic spline drawing class		
	This class is responsible for being a singleton (later) and then controlling the redrawing etc of each elemnt	
	Need to create a global track element as well that will hold all of the hash points	
	This will be a singleton class later on down the road
	When we need to implement individual objects to control splines, lets just overload our contstructor to take in these elements etc
	Can create an hash table wit hthe values linked to the proper elements
*/

// include project libraries first
#include "modules/spline.hpp"

// include c++ libraries


namespace application {

	class Controller {

		public:

			// later on we will pass in a 
			Controller(Spline * splines, int splineCounter); //pass in a pointer to a vector of arrays							
			~Controller();

		public:
			// functor operator is responsible for controlling the class on each and every run
			// this will be responsible for calling the proper pieces that need to be redrawn etc
			// this will be called from the application control function after it has properly changed the elements that need to be 
			void operator ()();


		// initialize data structures that will be used later on with subclassed controllers
		protected:
			Spline * splines;//this is the master track element
			int splineCounter;//how many elements are in the array of splines

	};
};
