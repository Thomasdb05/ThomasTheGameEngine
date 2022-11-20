#ifndef ENTITY_H
#define ENTITY_H
#include "Vector2.h"
#include "Renderer.h"

class Entity {
public:
	Renderer renderer;
	Vector2 position;
	float size;

	int loop();

	int setup();

	Entity();

	Entity(const char* filepath);

};

#endif
