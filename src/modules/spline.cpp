#include "modules/spline.hpp"

namespace application {

	#define S 0.5 
	const float dU = 0.05;

	// responsible for calculating the point and then repeatedly calling the correct point class with our result
	const float basisMatrix[4][4] = { 
		-1*S, 2-S, S-2,   S, 
		2*S,  S-3, 3-2*S, -1*S, 
		-1*S, 0,   S,     0,
		0,    1,   0,     0
	};//basis matrix		

	// std vector element	
	std::vector<Spline> * loadSplines(char * trackFile) {

		// load in the track file and then initialize each of the spline files from it to show to our users
		char * fileName = (char *)malloc(128 * sizeof(char));//initialize a string holder that is the size of 128 char string
		FILE * fileList;// size of our file list 
		std::vector<Spline> * splines;
		int	numberSplines;//this is how many spline files we need to read

		// open the file name
		fileList = fopen(trackFile, "r");

		// if the filelist is broken / screwed up exit the program
		if (fileList == NULL) {

			printf("Can't open file\n");
			exit(1);
		}

		// we should now know how many splines we have?
		fscanf(fileList, "%d", &numberSplines);

		// now that we know how many splines we need, we can properly initialize our vector
		splines = new std::vector<Spline>();		

		// loop through the number of splines that was specified by the beginning of the spline file and grab the corresponding file names etc
		for (int i = 0; i < numberSplines; i++) {

			// grab the file name
			fscanf(fileList, "%s", fileName);//grab the filename for the current spline

			// initial spline files' contents
			loadSpline(fileName, splines);//initialize this particular spline with our load spline functionality
		}

		free(fileName);//free the pointer that we created for our 128 character c string

		// return the pointer to the splines
		return splines;
	}

	// initialize the spline file by passing in the spline vector and the filename
	void loadSpline(char * fileName, std::vector<Spline> * splines) {

		// responsible for loading in an individual file to the spline array
		int length, //length of the spline file
			counter, //current element that we are assigning in the spline
			type;//type of spline that exists here

		// intiialize x,y,z elements for temporary allocation
		double x, y, z;//initialize temp values for this function to use for cleaner allocation


		// initialize the file
		FILE * splineFile = fopen(fileName, "r");

		// intiialize the type and length of the particular spline file
		fscanf(splineFile, "%d %d", &length, &type);			

		// initialize the spline structure for this element in the vector of splines
		splines->push_back(Spline());

		// use some pointer arithmetic to allocate the correct amount of memory for the points array in memory
		splines->back().points = (struct Point *)malloc(length * sizeof(struct Point));

		// now just initialize and save the number of points
		splines->back().numberPoints = length;

		while (fscanf(splineFile, "%lf %lf %lf", &x, &y, &z) != EOF) {

			splines->back().points[counter].x = x;
			splines->back().points[counter].y = y;
			splines->back().points[counter].z = z;

			++counter;//initialize the counter to increment once
		}
	} 


	void splineWorker(Point points[4], void (* callback)(Point p1, Point p2)) {
		// if we're working on a texture type item, we could simply have our callback multiply the correct elemnet by the correct piece before rendering

		// initialize the matrix
		float matrix[3][4];//initialize matrix multiplier!
		float vector[3];//the final vector we're working on afterwards

		// multiplierMatrix initialization via a lambda
		auto createMatrix = [=, &matrix] () -> float {

			// lambda to create the proper positional element
			auto positionValue = [=] (int x, int y) -> float { 

				int value;//cache the value we are looking for here!
				int pointCoordinate;//this is the x,y,z element

				// loop from 0->4 since our max depth is 4
				for (int i = 0; i < 4; i++) {

					// grab the correct coordiante from the right side coordinate
					if (x == 0) pointCoordinate = points[i].x;//x element
					else if (x == 1) pointCoordinate = points[i].y;//y element this 
					else pointCoordinate = points[i].z;//this is the final column of the element

					// fix up the value each time
					value += basisMatrix[y][i] * pointCoordinate;
				}
			};//create the position value element here

			// loop through x and y for our final pieces
			for (int x = 0; x < 3; x++)//final x position
				for (int y = 0; y < 4; y++)//final y position
					matrix[x][y] = positionValue(x,y);//set value using the intiialization lambda from above

			// return the matrix we created!	
		};//end of multiplier matrix initialization

		// p(u) = [u^3 u^2 u 1] M C
		for (int i = 0; i <= 1.0; i = i+dU) {
			// now calculate the actual element


		}	
	}	
};