#pragma once

#include <iostream>

namespace environment {

	// this should be a singleton class in the future
	// this environment class is responsible for drawing out the initial ground and everything contained within it
	class Environment {

		public:	

			Environment();
			~Environment();

		public:

			void operator()();//the actual controller for the environment namespace	
			void drawGround();//this will be responsible for drawing the ground later on with composed objects
			void drawSky();//this will be responsible for drawing the sky later with some sort of composition etc
	};
};