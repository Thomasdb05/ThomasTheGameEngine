#include"VAO.h"
#include<glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

/*

When drawing, only need to bind VAO as EBO and VBO are attached to it
VAO
/ \
VBO EBO

*/


void vao::generate(int objSize) {
	glGenVertexArrays(objSize, &VAO);
	objAmount = objSize;
}

void vao::bind() {
	glBindVertexArray(VAO);
}

void vao::unbind() {
	glBindVertexArray(0);
}

void vao::Delete() {
	glDeleteVertexArrays(objAmount, &VAO);
}

vao::vao() {

}
