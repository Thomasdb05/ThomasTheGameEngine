#include"Scene.h"

class MyScene : public Scene {
public:
    int setup() {
        Entity a("C:/Users/thoma/Downloads/sillycat.png");
        Entity b("C:/Users/thoma/Downloads/unsillycat.png");
           
        entityManager.addEntity(a);
        entityManager.addEntity(b);

        return 0;
    }

    int loop() {
        int x = 0;
        int y = 0;
        if (Input::A == Input::held) {
            x = -1;
        }
        else if (Input::D == Input::held) {
            x = 1;
        }

        if (Input::W == Input::held) {
            y = 1;
        }
        else if (Input::S == Input::held) {
            y = -1;
        }

        entityManager.entities[1].position += Vector2(x, y) * 0.01f;
        return 0;

    }
};