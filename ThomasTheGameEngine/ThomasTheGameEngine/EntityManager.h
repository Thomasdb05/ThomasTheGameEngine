#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Entity.h"
#include<vector>

class Collider;

class EntityManager {
public:
	int entityAmount = 0;

	int maxEntityAmount = 2;

	std::vector<Entity*> entities;
	std::vector<Collider*> colliders;

	//returns adress of entity in vector
	Entity* addEntity(Scene* scene, Entity* entity);

	Entity* addEntity(Scene* scene, Entity* entity, Vector2 pos);

	EntityManager();
};


#endif
