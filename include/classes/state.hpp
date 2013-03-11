#pragma once
#include <stdlib.h>
#include <iostream>

namespace application {

	enum mode {NORMAL, RIDE};
	enum coordinate {X, Y, Z};//useful for when the application wants to call a particular point on the element

	// class state for handling the application state
	class State {

		public:

			State();//initialize the state class
			~State();//kill the state class

		public: //getter functions	

			// get rotation 
			const float getRotation(coordinate axe);//get a
			const float getRotation(int axe);

			// get translation 
			const float getTranslation(coordinate axe);
			const float getTranslation(int axe);

			// get the scale of the element etc
			const float getScale(coordinate axe);
			const float getScale(int axe);

			// grab the distance the camera is back from the place
			const float getCameraDistance();
			//get the rotation of the camera etc 
			const float getCameraRotation(coordinate axe);	
			// get screen width / height
			const int getScreenWidth();
			// get sccreen height
			const int getScreenHeight();

		public: //setter functions	

			// set up the actual element
			void setRotation(coordinate axe, float value);//get a
			// set the translation etc of the element
			void setTranslation(coordinate axe, float value);

			// set the scale of the element in x,y,z
			void setScale(coordinate axe, float value);

			// set how far back the camera should be
			void setCameraDistance(float value);

			// camera rotation is in just x,y for now
			void setCameraRotation(coordinate axe, float value);	


		private: // get index functions 

			int getIndex(coordinate axe);

		private:

			// hold all of our data in a structure for easy use later on
			// make it non -- anonymous type to help with initialization!
			struct Data {

				// world elements
				float rotation[3];
				float translation[3];
				float scale[3];	

				// // camera elements
				float cameraRotation[2];
				float cameraDistance;

				// // screen dimensions
				int screenHeight;
				int screenWidth;

			} data;
			// end data structure!

	};// end object
}//end namespace




