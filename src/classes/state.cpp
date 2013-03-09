#include "classes/state.hpp"

namespace application {

	// implement the state class
	State::State() {

		Data temp = {

			//initialize rotation
			{0.0, 0.0, 0.0}, 		

			// initialize translation	
			{0.0, 0.0, 600},

			// initialize scale array
			{1.0, 1.0, 1.0},

			// initialize camera rotation
			{0.0, 0.0},

			// initialize camera distance
			60.0,

			// initialize screen height
			480,

			// initialize screen width
			600
		};

		data = temp;
	}		

	// destruct this singleton class
	State::~State() {

		// get rid of data if we have issues?

	}

	//************  PUBLIC GETTER FUNCTIONS **************//
	// grab rotation of element
	const float State::getRotation(coordinate axe) {


		return this->data.rotation[this->getIndex(axe)];


	}


	// grab translation in a particular direction
	const float State::getTranslation(coordinate axe) {

		return this->data.translation[this->getIndex(axe)];	
	}


	const float State::getScale(coordinate axe) {

		return this->data.scale[this->getIndex(axe)];

	}

	const float State::getCameraDistance() {

		return this->data.cameraDistance;

	}

	const float State::getCameraRotation(coordinate axe) {

		return this->data.cameraRotation[axe];

	}
	
	//*********** PUBLIC SETTER FUNCTIONS **********//	
	void State::setRotation(coordinate axe, float value) {

		this->data.rotation[this->getIndex(axe)] = value;	

	}

	// set up the translation of the world 
	void State::setTranslation(coordinate axe, float value) {

		this->data.translation[this->getIndex(axe)] = value;	

	}

	// set the scale of x / y / z of world
	void State::setScale(coordinate axe, float value) {


		this->data.scale[this->getIndex(axe)] = value;	
		
	}

	// set the distance back of the camera
	void State::setCameraDistance(float value) {

		this->data.cameraDistance = value;
		
	}

	// set the rotation of the camera, expect an x / y and a value
	void State::setCameraRotation(coordinate axe, float value) {

		this->data.cameraRotation[this->getIndex(axe)] = value;	
			
	}



	//************ PRIVATE HELPER FUNCTIONS ************//
	int State::getIndex(coordinate axe) {

		switch(axe) {

			case X: 

				return 0;

			case Y:		

				return 1;

			case Z:

				return 2;

			default:

				return 0;
		}

	}



}

