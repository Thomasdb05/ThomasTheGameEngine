#ifndef TEXTURE_H
#define TEXUTRE_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "stb_image.h"

class Texture {
public:
	GLuint texture;
	int width;
	int height;
	int colorchannelamount;
	
	void set(const char* filepath);

	Texture(const char* filepath);

	Texture();

	void Delete();
};

#endif
