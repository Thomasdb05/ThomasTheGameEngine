#include "Entity.h"
#include "Scene.h"

Component* Entity::addComponent(Component* component) {
	components.push_back(component);


	//Specific component handling
	Collider* collidercomponent = dynamic_cast<Collider*>(component);
	if (collidercomponent != nullptr) {
		scene->entityManager.colliders.push_back(collidercomponent);
	}

	return component;
}

int Entity::handleComponents() {

	bool handledColliders = false;
	for (int i = 0; i < components.size(); i++) {

		//specific component handling
		//TODO: make global instead of per entity, HUGE performance issues
		Collider* colliderComponent = dynamic_cast<Collider*>(components[i]);
		if (colliderComponent != nullptr) {
			colliderComponent->loop();
			handledColliders = true;
			continue;
		}

		PhysicsBody* physicsBodyComponent = dynamic_cast<PhysicsBody*>(components[i]);
		if (physicsBodyComponent != nullptr) {
			physicsBodyComponent->loop(&position);
			continue;
		}
		
		components[i]->loop();
		

	}
	return 0;
}

