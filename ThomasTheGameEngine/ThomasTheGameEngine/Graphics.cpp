#include "Graphics.h"

namespace Graphics {

    Window window;
    ShaderProgram shaderProgram;

    std::vector<Renderer> entities;

    int setupGraphics() {

        shaderProgram = ShaderProgram("vertexShader.txt", "fragmentShader.txt");

        Renderer a("C:/Users/thoma/Downloads/sillycat.png");
        Renderer b("C:/Users/thoma/Downloads/unsillycat.png");
        
        entities.push_back(a);
        entities.push_back(b);

        return 0;
    }

    int graphicsLoop() {

        while (!glfwWindowShouldClose(window.window))
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glUseProgram(shaderProgram.Program);

            for (int i = 0; i < entities.size(); i++) {
                entities[i].draw();
            }

            entities[1].setVerts(entities[1].getVertsAt(Vector2(-0.01f, 0.01f)));

            glfwSwapBuffers(window.window);
            glfwPollEvents();
        }


        for (int i = 0; i < entities.size(); i++) {
            glDeleteTextures(1, &entities[i].texture.texture);
        }
        shaderProgram.Delete();

        window.Delete();
        return 0;
    }
}