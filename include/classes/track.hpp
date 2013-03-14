#pragma once

// include some project libraries
#include "modules/spline.hpp"

// include proper standardized libraries
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <iostream> //include basic c++ 11 functionality here
#include <algorithm> //include foreach loop etc

/*
	A few important decisions have been made with this class
	This class is solely built to draw out the track and its beams
	We can't modularize the splines here so we're going to store a pointer to our global spline function and then we will create a master array in this class
	We're going to build out functions here to hold elements to store our current position etc	
*/
namespace track {

	class Track {

		public:
			Track(std::vector<Spline>* splines);			
			~Track();

		public://functions for access	

			void draw();//draw out the entire track
			void drawPiece();//draw out a piece of the track

		private:

			void init();//will be responsible for drawing the master linear array of points here

		protected:	

			std::vector<Spline>* splines;
			int numberPoints;//how many points we're holding in our element
			Point * points;//combination of all the points from each points
	};
};