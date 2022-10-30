#include "shaderProgram.h"

void ShaderProgram::Delete() {
	glDeleteProgram(Program);
}

ShaderProgram::ShaderProgram() {

}

ShaderProgram::ShaderProgram(const char* vertexpath, const char* fragmentpath) {
    readShaders(vertexpath, fragmentpath);

    linkShaders();

    //create shaderprogram, attach all shaders and wrap up
    Program = glCreateProgram();
    glAttachShader(Program, vertexShader);
    glAttachShader(Program, fragmentShader);
    glLinkProgram(Program);

    //shaders already in program so can be deleted
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void ShaderProgram::linkShaders() {

    //create, link and compile vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    //create, link and compile fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
}


void ShaderProgram::readShaders(const char* vertexpath, const char* fragmentpath) {
    std::string shaderDir = "C:\\Users\\thoma\\Documents\\GitHub\\ThomasTheGameEngine\\ThomasTheGameEngine\\Data\\Shaders\\";
    std::string line;

    std::ifstream vertexfile(shaderDir + vertexpath);
    if (vertexfile.is_open())
    {
        while (getline(vertexfile, line))
        {          
            vertexSourceStr += line + "\n";
        }
        vertexfile.close();
    }
    vertexSource = vertexSourceStr.c_str();

    std::ifstream fragmentfile(shaderDir + fragmentpath);
    if (fragmentfile.is_open())
    {
        while (getline(fragmentfile, line))
        {
            fragmentSourceStr += line + "\n";
        }
        fragmentfile.close();
    }
    fragmentSource = fragmentSourceStr.c_str();
}