#include "EntityManager.h"
#include "Entity.h"


Entity* EntityManager::addEntity(Scene* scene, Entity* entity) {
	entity->scene = scene;
	entities.push_back(entity);
	entityAmount++;

	return entity;
}

Entity* EntityManager::addEntity(Scene* scene, Entity* entity, Vector2 pos) {
	entity->scene = scene;
	entity->position = pos;
	entities.push_back(entity);
	entityAmount++;

	return entity;
}

EntityManager::EntityManager() {
	entities.reserve(maxEntityAmount);
	colliders.reserve(maxEntityAmount);
}