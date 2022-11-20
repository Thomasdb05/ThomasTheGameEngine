#ifndef GAME_H
#define GAME_H

#include"Entity.h"
#include"EntityManager.h"
#include"Scene.h"
#include"MyScene.h"

class Game {
public:
	Scene* currentScene;

	int loadScene(Scene* newScene);
	int setup();
	int loop();
	int end();
};

#endif