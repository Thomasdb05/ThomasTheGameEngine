#include"VBO.h"
#include<glad.h>
#include<GLFW/glfw3.h>

/*

When drawing, only need to bind VAO as EBO and VBO are attached to it
VAO
/ \
VBO EBO

*/


void vbo::generate(int objSize) {
	glGenBuffers(objSize, &VBO);
	objAmount = objSize;
}

void vbo::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void vbo::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void vbo::insert(int byteSize, GLfloat* data, GLenum drawMode) {
	glBufferData(GL_ARRAY_BUFFER, byteSize, data, drawMode);
}

void vbo::Delete() {
	glDeleteBuffers(objAmount, &VBO);
}

void vbo::setAttributes() {
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

vbo::vbo() {

}
