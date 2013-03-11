#pragma once

// include project libraries

// include c++ libraries
#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace application {

	// initialize basic control structures for splines etc
	struct Point {

		double x;
		double y;
		double z;
	};

	// basic spline structure
	struct Spline {

		int numberPoints;// number of points that we have to build out this particular spline	
		Point * points;//pointer to points
	};

	// initialize a spline loader function
	// this function is responsible for returning a spline array pointer to the caller
	std::vector<Spline> * loadSplines(char * trackFile);

	// initialize a function to load an individual spline file
	void loadSpline(char * splineFile, std::vector<Spline> * splines);
	
};

