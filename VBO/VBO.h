#include <cstdio>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#ifndef VBO_CLASS_H
#define VBO_CLASS_H

class VBO
{
    public:

    // VBO Reference.
    GLuint ID;

    // VBO Initilizer.
    VBO(GLfloat *vertices, GLsizeiptr size);

    // Bind The VBO.
    void Bind();
    // Unbind.
    void Unbind();
    // Delete.
    void Delete();
};

#endif