#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Entity.h"
#include<vector>

class EntityManager {
public:
	int entityAmount = 0;

	int maxEntityAmount = 2;
	std::vector<Entity> entities;

	//returns adress of entity in vector
	Entity* addEntity(Entity a);

	EntityManager();
};


#endif
