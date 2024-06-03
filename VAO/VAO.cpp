#include "VAO.h"

VAO::VAO() 
{
    glGenVertexArrays(1, &ID);
}

// Binds the VAO.
void VAO::Bind() 
{
    // Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(ID);
}

// Links the VAO to the VBO.
void VAO::LinkVBO(VBO &VBO, GLuint layout)
{
    // Configure the Vertex Attribute so that OpenGL knows how to read the VBO
    VBO.Bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

// Unbinds the VAO.
void VAO::Unbind() 
{
    // Unbinds the VAO by binding it to 0.
	glBindVertexArray(0);
}

void VAO::Delete() 
{
    glDeleteBuffers(1, &ID);
}