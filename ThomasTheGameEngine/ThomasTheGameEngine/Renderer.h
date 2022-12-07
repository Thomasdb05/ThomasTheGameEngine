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
#include "Component.h"

class Renderer : public Component {
public:
	vao VAO;
	vbo VBO;
	ebo EBO;

	std::vector<GLfloat> Vertices;

	Texture texture;

	int loop();

	int Delete();

	std::vector<GLfloat> getWorldVerts();

	std::vector<GLfloat> getVertsAt(Vector2 pos);

	void setVerts(std::vector<GLfloat> vertices);

	Renderer(Entity* Parent, const char* texpath);

	Renderer(Entity* Parent);
};


#endif