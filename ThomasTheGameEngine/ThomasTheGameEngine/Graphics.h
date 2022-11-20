#ifndef GRAPHICS_H
#define GRAPHICS_H

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include "ShaderProgram.h"
#include "Window.h"

namespace Graphics {

    extern Window window;
    extern ShaderProgram shaderProgram;

    int clearScreen();

    int setupGraphics();

	int graphicsLoop();

    int graphicsEnd();

}

#endif