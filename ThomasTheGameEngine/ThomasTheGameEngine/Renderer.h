#ifndef RENDERER_H
#define RENDERER_H

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "Shapes.h"
#include "Vector2.h"

// to fix circular dependency, header added in Entity.cpp
class Entity;

class Renderer {
public:
	Entity* parent;

	vao VAO;
	vbo VBO;
	ebo EBO;

	std::vector<GLfloat> Vertices;

	Texture texture;

	std::vector<GLfloat> getWorldVerts();

	std::vector<GLfloat> getVertsAt(Vector2 pos);

	void setTexture(const char* filepath);

	void render();

	void setVerts(std::vector<GLfloat> vertices);

	void Delete();

	Renderer(const char* texpath);

	Renderer();
};


#endif