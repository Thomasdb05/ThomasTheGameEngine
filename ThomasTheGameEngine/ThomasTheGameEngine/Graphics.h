#ifndef GRAPHICS_H
#define GRAPHICS_H

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include "ShaderProgram.h"
#include "Renderer.h"
#include "Window.h"

namespace Graphics {

    extern Window window;
    extern ShaderProgram shaderProgram;

    extern std::vector<Renderer> entities;

	int graphicsLoop();

	int setupGraphics();
}

#endif