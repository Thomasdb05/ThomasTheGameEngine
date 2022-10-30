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
	
	void setTexture(const char* filepath);

	Texture(const char* filepath);

	Texture();
};

#endif
