#ifndef WINDOW_H
#define WINDOW_H

#include<iostream>
#include<glad.h>
#include<GLFW/glfw3.h>
#include<vector>

class Window {
public:
    GLFWwindow* window;

    int createWindow();

    void Delete();

};


#endif
