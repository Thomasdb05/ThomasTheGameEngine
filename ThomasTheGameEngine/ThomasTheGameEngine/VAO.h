#ifndef VAO_H
#define VAO_H

#include<glad.h>
#include<GLFW/glfw3.h>


class vao {
public:
	GLuint VAO;
	int objAmount;

	void generate(int objSize);

	void bind();

	void unbind();

	void Delete();

	vao();
};

#endif