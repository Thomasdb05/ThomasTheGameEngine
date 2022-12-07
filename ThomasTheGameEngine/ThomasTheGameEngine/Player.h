#pragma once
#include"Entity.h"

class Player : public Entity {
public:
    Collider* collider;
    Renderer* renderer;
    PhysicsBody* physics;
    bool isP2 = false;

    int setup() {
        if (isP2) {
            renderer = new Renderer(this, "C:/Users/thoma/Downloads/sillycat.png");
        }
        else {
            renderer = new Renderer(this, "C:/Users/thoma/Downloads/unsillycat.png");
        }
        addComponent(renderer);
        collider = new Collider(this);
        addComponent(collider);
        physics = new PhysicsBody(this, collider);
        if (isP2) {
            physics->grav = 0.0f;
        }
        addComponent(physics);

        return 0;
	}

	int loop() {
        if (collider->isColliding()) {
            physics->vel.y = 0;
        }
        int x = 0;
        int y = 0;
        if (!isP2) {
            if (Input::A == Input::held) {
                x = -1;
            }
            else if (Input::D == Input::held) {
                x = 1;
            }

            if (Input::W == Input::pressed) {
                std::cout << "jump!!!" << std::endl;
                physics->vel = Vector2(0, 0.02);
            }
            else if (Input::S == Input::held) {
                y = -1;
            }
        } else {
            if (Input::J == Input::held) {
                x = -1;
            }
            else if (Input::L == Input::held) {
                x = 1;
            }

            if (Input::I == Input::held) {
                y = 1;
            }
            else if (Input::K == Input::held) {
                y = -1;
            }
        }
        physics->vel.x = x * 0.01f;
        return 0;
	}
};