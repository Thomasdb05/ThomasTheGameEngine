#ifndef EBO_H
#define EBO_H

#include<glad.h>
#include<GLFW/glfw3.h>


class ebo {
public:
	GLuint EBO;
	int objAmount;

	void generate(int objSize);

	void bind();

	void unbind();

	void insert(int byteSize, GLuint* data, GLenum drawMode);

	void Delete();

	ebo();
};

#endif