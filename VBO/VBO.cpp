#include <cstdio>
#include <math.h>

#include "VBO.h"

// Main VBO.
VBO::VBO(GLfloat* vertices, GLsizeiptr size) {
    // Generate a buffer for VBO.
    glGenBuffers(1, &ID); // We use ID, so we can properly reference VBO from main function.
    // Bind the VBO specifying it's a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, ID);
    // Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

// Bind VBO.
void VBO::Bind() 
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

// Unbind VBO.

void VBO::Unbind() 
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Deletes the VBO
void VBO::Delete()
{
	glDeleteBuffers(1, &ID); // Delete buffer, based on num elements, (1) and element to delete (VBO).
}