#ifndef COMPONENT_H
#define COMPONENT_H

//Defined here to prevent circular dependency
class Entity;

class Component {
public:
	Entity* parent;

	virtual int loop() = 0;
	virtual int Delete() = 0;

	Component(Entity* Parent) {
		parent = Parent;
	}

	Component() {};
};

#endif