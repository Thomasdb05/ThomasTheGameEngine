#include "PhysicsBody.h"

int PhysicsBody::loop(Vector2* entityPos) {
	vel.y -= grav;

	if (vel.length() == 0) {
		return 0;
	}
	float smallestDist = 1;
	bool isColliding = false;

	*entityPos += vel * smallestDist;

	//TODO: make this a global update, and not a function part of collision, now looping twice
	//just so colliders are updated BEFORE solving
	if (colliders.size() > 0) {
		colliders[0]->loop();
	}
	for (int i = 0; i < colliders.size(); i++) {
		if (colliders[i]->isColliding()) {
			colliders[i]->solveCollisions();
			isColliding = true;
		}
	}
	

	return 0;
}

int PhysicsBody::loop() {
	return -1;
}

int PhysicsBody::Delete() {
	return 0;
}

PhysicsBody::PhysicsBody(Entity* Parent, std::vector<Collider*> Colliders) {
	parent = Parent;
	colliders = Colliders;
}

PhysicsBody::PhysicsBody(Entity* Parent, Collider* Collider) {
	parent = Parent;
	colliders.push_back(Collider);
}

PhysicsBody::PhysicsBody(Entity* Parent) {
	parent = Parent;
}
