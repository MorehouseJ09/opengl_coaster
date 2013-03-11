#pragma once

// include some project libraries
#include "modules/spline.hpp"

// include proper standardized libraries
#include <vector>

/*
	A few important decisions have been made with this class
	This class is solely built to draw out the track and its beams
	We can't modularize the splines here so we're going to store a pointer to our global spline function and then we will create a master array in this class
	We're going to build out functions here to hold elements to store our current position etc	
*/

namespace application {

	class Track {

		public:
			Track(std::vector<Point>* points);			
			~Track();

		private:

			init();//will be responsible for drawing the master linear array of points here

		protected:	

			std::vector<Spline>* spline;
			int numberPoints;//how many points we're holding in our element
			Point * points;//


				

	};




}