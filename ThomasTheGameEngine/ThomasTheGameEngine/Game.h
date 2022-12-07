#ifndef GAME_H
#define GAME_H

#include"Entity.h"
#include"EntityManager.h"
#include"Scene.h"
#include"MyScene.h"
#include"Graphics.h"

class Game {
public:
	Scene* currentScene;

	int setup();
	int loop();

	int sceneloop() {
		currentScene->loop();
		for (int i = 0; i < currentScene->entityManager.entities.size(); i++) {
			Entity* currentEntity = currentScene->entityManager.entities[i];
			currentEntity->handleComponents();
			currentEntity->loop();
		}
		return 0;
	}

	int end() {
		Graphics::graphicsEnd();

		free(currentScene);
		return 0;
	}

	int loadScene(Scene* newScene) {
		currentScene = newScene;
		if (!currentScene->isSetup) {

			currentScene->setup();
			for (int i = 0; i < currentScene->entityManager.entities.size(); i++) {
				currentScene->entityManager.entities[i]->setup();
			}
			currentScene->isSetup = true;
		}
		return 0;
	}
};

#endif