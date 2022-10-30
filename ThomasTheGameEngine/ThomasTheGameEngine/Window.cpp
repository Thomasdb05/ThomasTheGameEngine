#include "Window.h"

int Window::createWindow() {

    glfwInit();

    // Hint at openGL version and Core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    window = glfwCreateWindow(800, 800, "Thomas The Game Engine", NULL, NULL);

    if (window == NULL)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return -1;
    }
    
    glViewport(0, 0, 800, 800);
    return 0;
}

void Window::Delete() {
    glfwDestroyWindow(window);
    glfwTerminate();
}