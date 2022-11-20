#include "Entity.h"
#include<iostream>


int Entity::loop() {
	return -1;
}

int Entity::setup() {
	return -1;
}

Entity::Entity() {
	size = 1.0f;

	renderer.parent = this;
}

Entity::Entity(const char* filepath) {
	size = 1.0f;

	renderer.parent = this;
	renderer.texture.set(filepath);
}
