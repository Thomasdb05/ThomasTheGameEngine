#ifndef ENTITY_H
#define ENTITY_H
#include "Vector2.h"
//components
#include "Renderer.h"
#include "Collider.h"
#include "PhysicsBody.h"

#include "Flags.h"
#include<iostream>
#include<algorithm>

class Scene;

class Entity {
public:

	std::vector<Component*> components;
	Scene* scene;

	Vector2 position = Vector2(0.0f, 0.0f);
	Vector2 size = Vector2(1.0f, 1.0f);
	int flag = -1;
	bool isSetup = false;

	virtual int loop() = 0;

	virtual int setup() = 0;

	Component* addComponent(Component* component);

	int handleComponents();

	

};

#endif
