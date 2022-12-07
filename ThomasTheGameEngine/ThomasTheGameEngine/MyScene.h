#include"Scene.h"

class MyScene : public Scene {
public:
    int setup() {
        Player* a = new Player();
           
        entityManager.addEntity(this, a, Vector2(0.0f, 1.0f));
        a->size = Vector2(0.3f, 0.3f);

        Player* b = new Player();
        b->isP2 = true;
        b->size = Vector2(0.3f, 0.3f);
        b->size = Vector2(3, 1);
        entityManager.addEntity(this, b, Vector2(0.0f, -0.5f));
        return 0;
    }

    int loop() {
        return 0;
    }
};