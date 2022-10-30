#include"EBO.h"
#include<glad.h>
#include<GLFW/glfw3.h>


void ebo::generate(int objSize) {
	glGenBuffers(objSize, &EBO);
	objAmount = objSize;
}

void ebo::bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void ebo::unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ebo::insert(int byteSize, GLuint* data, GLenum drawMode) {
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, byteSize, data, drawMode);
}

void ebo::Delete() {
	glDeleteBuffers(objAmount, &EBO);
}

ebo::ebo() {

}
