#ifndef COLLIDER_H
#define COLLIDER_H

#include<vector>
#include "Component.h"
#include<iostream>
#include "Vector2.h"

class Entity;

class Collider : public Component {
public:
	//To apply the Seperating Axis Theorem
	struct intersectBox {
		Collider* collider;
		float pos;
		bool isBegin = false;

		intersectBox(Collider* parent, float Pos, bool IsBegin) {
			collider = parent; pos = Pos; isBegin = IsBegin;
		}
	};
	static bool SAT_sorter(intersectBox const& boxA, intersectBox const& boxB) {
		return boxA.pos < boxB.pos;
	}

	Entity* parent;
	Vector2 size = Vector2(1.0f, 1.0f);
	Vector2 pos = Vector2(0.0f, 0.0f);
	int flag = -1;
	std::vector<Collider*> colliders;

	//Updates all colliders in pool, not just own, call once on scene update
	int loop();

	int Delete();

	bool isColliding(Collider* collider);
	bool isColliding(int Flag);
	bool isColliding();

	int solveCollisions();

	Vector2 getWorldPos();
	Vector2 getWorldSize();

	std::vector<std::vector<Collider*>> SATsort(std::vector<Collider*> colliderPool, bool isY);

	Collider(Entity* Parent, Vector2 Size, Vector2 Pos);
	Collider(Entity* Parent, Vector2 Size);
	Collider(Entity* Parent);
};

#endif

