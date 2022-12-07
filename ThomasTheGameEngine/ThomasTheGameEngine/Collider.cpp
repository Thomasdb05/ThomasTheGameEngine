#include"Collider.h"
#include "Entity.h"
#include "Scene.h"

//Application of SAT
int Collider::loop() {

	std::vector<std::vector<Collider*>> xIntersectors;
	xIntersectors = SATsort(parent->scene->entityManager.colliders, false);

	for (int i = 0; i < xIntersectors.size(); i++) {
		std::vector<std::vector<Collider*>> intersectors = SATsort(xIntersectors[i], true);
		for (int j = 0; j < intersectors.size(); j++) {
			for (int k = 0; k < intersectors[j].size(); k++) {
				intersectors[j][k]->colliders = intersectors[j];

				//filter out self colliders
				for (int l = 0; l < intersectors[j][k]->colliders.size(); l++) {
					if (intersectors[j][k]->colliders[l] == intersectors[j][k]) {
						intersectors[j][k]->colliders.erase(intersectors[j][k]->colliders.begin() + l);
					}
				}
			}
		}
	}
	
	return 0;
}

int Collider::Delete() {
	free(this);
	return 0;
}

bool Collider::isColliding() {
	return colliders.size() > 0;
}

bool Collider::isColliding(Collider* collider) {
	for (int i = 0; i < colliders.size(); i++) {
		if (colliders[i] == collider) {
			return true;
		}
	}
	return false;
}

int Collider::solveCollisions() {
	Vector2 worldSize = getWorldSize() / 2;
	Vector2 worldPos = getWorldPos();

	for (int i = 0; i < colliders.size(); i++) {
		Vector2 otherWorldPos = colliders[i]->getWorldPos();
		Vector2 otherWorldSize = colliders[i]->getWorldSize() / 2;

		Vector2 solveVec = (otherWorldPos - worldPos).abs() - worldSize - otherWorldSize;

		if (std::abs(solveVec.x) < std::abs(solveVec.y)) {
			if (otherWorldPos.x > worldPos.x) {
				solveVec = solveVec * -1;
			}
			parent->position.x -= solveVec.x;
		}
		else {
			if (otherWorldPos.y > worldPos.y) {
				solveVec = solveVec * -1;
			}
			parent->position.y -= solveVec.y;
		}
	}
	return 0;
}

bool Collider::isColliding(int Flag) {
	for (int i = 0; i < colliders.size(); i++) {
		if (colliders[i]->flag == Flag) {
			return true;
		}
	}
	return false;
}

/*
float Collider::castAtPos(Vector2 newPos, Collider* collider) {
	//check if intersecting at new position
	Vector2 oldEntityPos = parent->position;
	Vector2 oldPos = getWorldPos();
	Vector2 vel = newPos - oldPos;
	parent->position += vel;
	if (!checkIntersect(collider)) {
		return 1.0f;
	}


	Vector2 moveDir = newPos - oldPos;
	Vector2 otherWorldPos = collider->getWorldPos();
	Vector2 otherWorldSize = collider->getWorldSize();
	Vector2 worldSize = getWorldSize();
	/*
	rcx * tx + oldpospoint[?]x = x(border) -> tx = (x(border) - oldpospoint[?]x)/rcx
	rcy * ty + oldpospoint[?]y = y(border) -> ty = (y(border) - oldpospoint[?]y)/rcx

	border is closest line segment of othercollider, do this for all points of colliderbox
	
	float xBorder = otherWorldPos.x + (otherWorldSize.x / 2);
	float yBorder = otherWorldPos.y + (otherWorldSize.y / 2);
	if (oldPos.x < otherWorldPos.x) {
		xBorder = otherWorldPos.x - (otherWorldSize.x / 2);
	}
	if (oldPos.y < otherWorldPos.y) {
		yBorder = otherWorldPos.y - (otherWorldSize.y / 2);
	}

	float distPerPoint[4];
	Vector2 oldPoints[4] {
		Vector2(oldPos.x - (worldSize.x/2), oldPos.y - (worldSize.y / 2)),
		Vector2(oldPos.x + (worldSize.x / 2), oldPos.y - (worldSize.y / 2)),
		Vector2(oldPos.x + (worldSize.x / 2), oldPos.y + (worldSize.y / 2)),
		Vector2(oldPos.x - (worldSize.x / 2), oldPos.y + (worldSize.y / 2))
	};
	std::cout << "--------" << std::endl;
	for (int i = 0; i < 4; i++) {
		float tx = (xBorder - oldPoints[i].x) / moveDir.x;
		float ty = (yBorder - oldPoints[i].y) / moveDir.y;
		
		distPerPoint[i] = tx < ty ? tx : ty;
		if (std::isinf(tx)) {
			distPerPoint[i] = ty;
		} else if(std::isinf(ty)) {
			distPerPoint[i] = tx;
		}
	
		std::cout << Vector2(tx, ty).str() << " so: " << distPerPoint[i] << std::endl;
	}

	//Get smallest distance
	float smallestDist = distPerPoint[0];
	for (int i = 1; i < 4; i++) {
		if (distPerPoint[i] < smallestDist && !std::isinf(distPerPoint[i])) {
			smallestDist = distPerPoint[i];
		}
	}

	return smallestDist;
}

float Collider::castAtPos(Vector2 newPos) {
	std::vector<Collider*> pool = parent->scene->entityManager.colliders;

	float smallestDistance = 1;

	for (int i = 0; i < pool.size(); i++) {
		if (pool[i] != this) {
			float castDist = castAtPos(newPos, pool[i]);
			if (castDist < smallestDistance) {
				smallestDistance = castDist;
			}
		}
	}
	return smallestDistance;
}
*/

std::vector<std::vector<Collider*>> Collider::SATsort(std::vector<Collider*> colliderPool, bool isY) {
	
	//setup insersectBox points
	int pointSize = colliderPool.size() * 2;
	intersectBox* Intersectpoints = (intersectBox*)malloc(sizeof(intersectBox) * pointSize);

	for (int i = 0; i < pointSize; i += 2) {
		colliderPool[i / 2]->colliders.clear();
		Collider* currentCollider = colliderPool[i/2];
		Vector2 worldPosVec = currentCollider->getWorldPos();
		Vector2 worldSizeVec = currentCollider->getWorldSize();

		float worldPos;
		float sizeOffset;
		if (isY) {
			worldPos = worldPosVec.y;
			sizeOffset = worldSizeVec.y;

		} else {
			worldPos = worldPosVec.x;
			sizeOffset = worldSizeVec.x ;
		}
		sizeOffset /= 2;
		Intersectpoints[i] = intersectBox(currentCollider, worldPos - sizeOffset, true);
		Intersectpoints[i + 1] = intersectBox(currentCollider, worldPos + sizeOffset, false);

	}

	std::sort(Intersectpoints, Intersectpoints + pointSize, &SAT_sorter);

	//get intersection groups (on specified axis)
	std::vector<std::vector<Collider*>> IntersectGroups;
	IntersectGroups.push_back(std::vector<Collider*>());
	int groupIndex = 0;

	int colliderIndex = 0;

	for (int i = 0; i < pointSize; i++) {
		if (Intersectpoints[i].isBegin) {
			if (colliderIndex > 0) {
				IntersectGroups[groupIndex].push_back(Intersectpoints[i].collider);
				if (colliderIndex == 1) {
					IntersectGroups[groupIndex].push_back(Intersectpoints[i - 1].collider);
				}
			}
			colliderIndex++;
		} else {
			if (colliderIndex > 1) {
				IntersectGroups.push_back(std::vector<Collider*>());
				groupIndex++;
			}
			colliderIndex = 0;
		}
	}

	return IntersectGroups;
}

Vector2 Collider::getWorldPos() {
	return Vector2(parent->position + pos);
}

Vector2 Collider::getWorldSize() {
	return Vector2(parent->size.x * size.x, parent->size.y * size.y);
}



Collider::Collider(Entity* Parent, Vector2 Size, Vector2 Pos) {
	std::cout << "addr: " << this;
	parent = Parent;
	pos = Pos;
	size = Size;
}
Collider::Collider(Entity* Parent, Vector2 Size) {
	parent = Parent;
	size = Size;
}
Collider::Collider(Entity* Parent) {
	parent = Parent;
}