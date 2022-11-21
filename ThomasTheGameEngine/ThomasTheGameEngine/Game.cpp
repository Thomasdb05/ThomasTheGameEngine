#include "Game.h"

int Game::loadScene(Scene* newScene) {
	currentScene = newScene;
	if (!currentScene->isSetup) {
		currentScene->setup();
		currentScene->isSetup = true;
	}
	return 0;
}

int Game::setup() {
	// create scenes on heap
	static MyScene scene;


	
	loadScene(&scene);
	return 0;
}

int Game::loop() {
	currentScene->loop();
	return 0;
}

int Game::end() {
	free(currentScene);
	return 0;
}