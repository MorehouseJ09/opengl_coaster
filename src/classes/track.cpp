#include "classes/track.hpp"


using namespace application;

namespace track {

	Track::Track(std::vector<Spline> * splines) : splines(splines) {

		this->init();//initialize the master array of all elements	
	} 

	void Track::init() {

		// initialize the master array of points here
		for_each(this->splines->begin(), this->splines->end(), [this] (Spline input) {
			this->numberPoints += input.numberPoints;	
		});

		// now allocate the proper size array for the points etc
		this->points = (struct Point *)malloc(this->numberPoints * sizeof(struct Point));					

		// initialize the counter element
		int counter = 0;

		// now we need to copy the current spline into the proper place in the master array
		for_each(this->splines->begin(), this->splines->end(), [this, &counter](Spline spline) {

			// copy the points to the other 
			std::memcpy(&this->points[counter], spline.points, spline.numberPoints * sizeof(Point));

			// up the counter to the proper starting position
			counter += spline.numberPoints;//set the position in relative points
		});
	}

	// destroy track elements
	Track::~Track() {

		// deallocate the points object
		// dealloc(this->points);

	}

	void Track::draw() {

		// responsible for drawing the entire track out		

	}

	void drawPiece() {

		// draw out a piece of the element


	}
}


