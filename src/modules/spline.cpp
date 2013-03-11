#include "modules/spline.hpp"

namespace application {

	std::vector<Spline> * loadSplines(char * trackFile) {

		// load in the track file and then initialize each of the spline files from it to show to our users
		char * fileName = (char *)malloc(128 * sizeof(char));//initialize a string holder that is the size of 128 char string
		FILE * fileList;// size of our file list 
		FILE * fileSpline;//individual spline file
		std::vector<Spline> * splines;
		int iType,
			numberSplines,//this is how many spline files we need to read
			i = 0,
			j, 
			iLength;//

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
		splines = new std::vector<Spline>(numberSplines);		

		for (int i = 0; i < numberSplines; i++) {

			fscanf(fileList, "%s", fileName);//grab the filename for the current spline
			loadSpline(fileName, splines);//initialize this particular spline with our load spline functionality
		}

		return splines;
	}

	// initialize the spline file by passing in the spline vector and the filename
	void loadSpline(char * fileName, std::vector<Spline> * splines) {

		// responsible for loading in an individual file to the spline array
		int length, //length of the spline file
			type;//type of spline that exists here

		// initialize the file
		FILE * splineFile = fopen(fileName, "r");

		// intiialize the type and length of the particular spline file
		fscanf(splineFile, "%d %d", length, type);			

		// initialize our original spline 
		splines->push_back(Spline());

		// use some pointer arithmetic to allocate the correct amount of memory for the points array in memory
		splines->back().points = (struct Point *)malloc(length * sizeof(struct Point));
		// now just initialize and save the number of points
		splines->back().numberPoints = length;
	} 
		

};