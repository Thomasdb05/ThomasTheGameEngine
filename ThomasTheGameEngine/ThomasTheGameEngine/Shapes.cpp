#include "Shapes.h"

namespace Shapes {
    std::vector<GLfloat> boxVertices = {
            -0.5f, -0.5f,   0.0f, 0.0f,
            -0.5f, 0.5f,    0.0f, 1.0f,
            0.5f, 0.5f,     1.0f, 1.0f,
            0.5f, -0.5f,    1.0f, 0.0f
    };

    std::vector<GLuint> boxIndices =
    {
        0, 2, 1,
        0, 3, 2
    };
}