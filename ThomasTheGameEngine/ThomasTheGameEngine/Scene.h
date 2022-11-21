#ifndef SCENE_H
#define SCENE_H

#include"EntityManager.h"
#include"Entity.h"
#include"InputManager.h"
#include<iostream>

class Scene {
public:
	EntityManager entityManager;
	bool isSetup = false;

	virtual int setup() = 0;
	//for any occasional scene management
	virtual int loop() = 0;


	int render() { 
		for (int i = 0; i < entityManager.entities.size(); i++) {
			entityManager.entities[i].renderer.render();
		}
		return 0;
	}
};

#endif