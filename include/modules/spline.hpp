#pragma once

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
};

