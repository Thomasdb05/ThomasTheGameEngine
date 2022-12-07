#ifndef SCENE_H
#define SCENE_H

#include"EntityManager.h"
#include"InputManager.h"
#include<iostream>
#include"Player.h"

class Scene {
public:
	EntityManager entityManager;
	bool isSetup = false;

	virtual int setup() = 0;
	//for any occasional scene management
	virtual int loop() = 0;


};

#endif