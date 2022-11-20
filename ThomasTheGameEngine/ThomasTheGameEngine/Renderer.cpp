#include "Entity.h"
#include "Renderer.h"
#include<iostream>

void Renderer::render() {

    std::vector<GLfloat> originalverts = Vertices;
    std::vector<GLfloat> parentadjustedverts;

    // adjust vertices to world positions for drawing
    if (parent) {
        setVerts(getWorldVerts());
    }

    glBindTexture(GL_TEXTURE_2D, texture.texture);
    VAO.bind();

    // draw primitives, number of indices, datatype of indices, index of indices
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // reset vertices to local positions
    setVerts(originalverts);
}

void Renderer::Delete() {
    texture.Delete();
    VAO.Delete();
    VBO.Delete();
    EBO.Delete();
}

std::vector<GLfloat> Renderer::getWorldVerts() {
    std::vector<GLfloat> verts = Vertices;

    for (int i = 0; i < Vertices.size(); i += 4) {
        verts[i] /= parent->size;
        verts[i + 1] /= parent->size;

        verts[i] += parent->position.x;
        verts[i + 1] += parent->position.y;
    }

    return verts;
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
    texture.set(texpath);
}

Renderer::Renderer() {
    VAO.generate(1);
    VBO.generate(1);
    EBO.generate(1);

    setVerts(Shapes::boxVertices);
}