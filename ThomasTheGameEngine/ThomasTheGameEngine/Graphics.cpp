#include "Graphics.h"

namespace Graphics {

    Window window;
    ShaderProgram shaderProgram;


    int setupGraphics() {
        shaderProgram = ShaderProgram("vertexShader.txt", "fragmentShader.txt");

        return 0;
    }

    int clearScreen() {
        glClear(GL_COLOR_BUFFER_BIT);

        return 0;
    }

    int graphicsLoop() {
        glUseProgram(shaderProgram.Program);
        glfwSwapBuffers(window.window);
        glfwPollEvents();

        return 0;
        
    }

    int graphicsEnd() {
        /*
        for (int i = 0; i < entityManager.entityAmount; i++) {
            entityManager.entities[i].renderer.Delete();
        }
        shaderProgram.Delete();
        */

        window.Delete();
        return 0;
    }
}