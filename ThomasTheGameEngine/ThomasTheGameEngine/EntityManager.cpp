#include "EntityManager.h"
#include<iostream>


Entity* EntityManager::addEntity(Entity a) {
	entities.push_back(a);
	entities[entityAmount].renderer.parent = &entities[entityAmount];
	entityAmount++;

	return a.renderer.parent;
}

EntityManager::EntityManager() {
	entities.reserve(maxEntityAmount);
}