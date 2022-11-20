#include "Game.h"

int Game::loadScene(Scene* newScene) {
	currentScene = newScene;
	if (!currentScene->isSetup) {
		((MyScene*)currentScene)->setup();
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
	((MyScene*)currentScene)->loop();
	return 0;
}

int Game::end() {
	free(currentScene);
	return 0;
}