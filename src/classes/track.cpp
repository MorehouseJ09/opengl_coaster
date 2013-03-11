#include "classes/track.hpp"

namespace application {

	Track::Track(std::vector<Spline> * splines) : splines(splines) {





	} 

	void Track::init() {

		// initialize the master array of points here
		for_each(this->splines->begin(), this->splines->end(), [this->numberPoints] (Spline input) {
			this->numberPoints += input.numberPoints;	
		});

		// now allocate the proper size array for the points etc
			


	}

	Track::~Track() {



	}





}