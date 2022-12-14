#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"

void Texture::set(const char* texpath) {
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(texpath, &width, &height, &colorchannelamount, 0);

    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    //setup texture settings
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
}
Texture::Texture(const char* texpath) {
    set(texpath);
}

Texture::Texture() {

}

void Texture::Delete() {
    glDeleteTextures(1, &texture);
}