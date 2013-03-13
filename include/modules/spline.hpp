#pragma once

// include project libraries

// include c++ libraries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <string.h>


namespace application {

	// initialize basic control structures for splines etc
	struct Point {

		double x;
		double y;
		double z;
	};

	// declare our change element for the cotmull-rom calculation
	extern const float S;//s increment
	extern const float dU;//increment of u
	extern const float basisMatrix[4][4];//initialize catmull-rom basis matrix

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

	// spline worker is responsible for calculating the intermediate points and drawing out the pieces in between them etc
	void splineWorker(Point points[4], void(*callback)(Point p1, Point p2));

};