#ifndef PHYSICS_H
#define PHYSICS_H

#include "Component.h"
#include "Collider.h"
#include "Vector2.h"
#include<vector>

class PhysicsBody : public Component {
public:

	std::vector<Collider*> colliders;
	Vector2 vel;
	float grav = 0.00098;

	int loop(Vector2* entityPos);

	int loop();

	int Delete();

	PhysicsBody(Entity* Parent, std::vector<Collider*> Colliders);
	
	PhysicsBody(Entity* Parent, Collider* Collider);

	PhysicsBody(Entity* Parent);
};


#endif