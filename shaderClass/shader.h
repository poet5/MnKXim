#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H
#include <glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string get_file_contents(const char* filename); // Will allow us to get contents of vertex and shader files.

class Shader
{
    public:
    //Shader Reference.
    GLuint ID;
    //Links Shader to Vertex and Fragment Shaders.
    Shader(const char * vertexFile, const char * fragmentFile); 

    void Activate(); // Activate shader program.

    void Delete(); // Delete the shader program.
};
#endif