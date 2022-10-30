#include "Renderer.h"
#include<iostream>


void Renderer::draw() {

    glBindTexture(GL_TEXTURE_2D, texture.texture);
    VAO.bind();

    // Draw primitives, number of indices, datatype of indices, index of indices
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::Delete() {
    VAO.Delete();
    VBO.Delete();
    EBO.Delete();
}

std::vector<GLfloat> Renderer::getVertsAt(Vector2 pos) {
    std::vector<GLfloat> verts = Vertices;

    for (int i = 0; i < Vertices.size(); i += 4) {
        verts[i] += pos.x;
        verts[i+1] += pos.y;
    }

    return verts;
}

void Renderer::setVerts(std::vector<GLfloat> vertices) {
    VAO.bind();
    VBO.bind();
    EBO.bind();
    VBO.insert(vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
    EBO.insert(Shapes::boxIndices.size() * sizeof(GLuint), Shapes::boxIndices.data(), GL_STATIC_DRAW);

    VBO.setAttributes();

    VBO.unbind();
    VAO.unbind();
    EBO.unbind();

    Vertices = vertices;
}

Renderer::Renderer(const char* texpath) {

    VAO.generate(1);
    VBO.generate(1);
    EBO.generate(1);

    setVerts(Shapes::boxVertices);
    texture.setTexture(texpath);
}

Renderer::Renderer() {
    VAO.generate(1);
    VBO.generate(1);
    EBO.generate(1);

    setVerts(Shapes::boxVertices);
}