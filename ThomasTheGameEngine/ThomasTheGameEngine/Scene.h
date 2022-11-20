#ifndef SCENE_H
#define SCENE_H

#include"EntityManager.h"
#include"Entity.h"
#include"InputManager.h"
#include<iostream>

class Scene {
public:
	EntityManager entityManager;
	const std::type_info& sceneType = typeid(this);
	bool isSetup = false;

	int setup() { isSetup = true; return -1; }
	//for any occasional scene management
	int loop() { return -1; }


	int render() { 
		for (int i = 0; i < entityManager.entities.size(); i++) {
			entityManager.entities[i].renderer.render();
		}
		return 0;
	}
};

#endif