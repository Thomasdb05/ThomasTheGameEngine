#include "Game.h"


int Game::setup() {
	// create scenes on heap
	MyScene* scene = new MyScene();


	
	loadScene(scene);
	return 0;
}

int Game::loop() {

	return 0;
}