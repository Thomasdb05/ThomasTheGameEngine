#ifndef SHADER_H
#define SHADER_H

#include<iostream>
#include <glad.h>
#include<GLFW/glfw3.h>
#include <fstream>
#include <string>


class ShaderProgram {
public:
	GLuint Program;

	GLuint vertexShader;
	GLuint fragmentShader;

	std::string vertexSourceStr;
	std::string fragmentSourceStr;
	const char* vertexSource;
	const char* fragmentSource;

	void Delete();
	ShaderProgram();
	ShaderProgram(const char* vertexpath, const char* fragmentpath);
private:
	void readShaders(const char* vertexpath, const char* fragmentpath);
	void linkShaders();
};

#endif