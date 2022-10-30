#ifndef VBO_H
#define VBO_H

#include<glad.h>
#include<GLFW/glfw3.h>


class vbo {
public:
	GLuint VBO;
	int objAmount;

	void generate(int objSize);

	void bind();

	void unbind();

	void insert(int byteSize, GLfloat* data, GLenum drawMode);

	void Delete();

	void setAttributes();

	vbo();
};

#endif