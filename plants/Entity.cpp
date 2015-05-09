#include "Entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <vector>

// Constructor
Entity::Entity() {
  vertexData = new GLfloat;
  vertexBuffer = new GLuint;
}

// Get vertex data
GLfloat* Entity::getVertexData() {
  return vertexData;
}

// Set vertex data
void Entity::refreshBuffer() {
  // Generate & bind vertex buffer
  glGenBuffers(1, vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, *vertexBuffer);
      
  // Pass updated vertices to OpenGL.
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLuint)*9, vertexData, GL_STATIC_DRAW);

}

// Get vertex buffer
GLuint* Entity::getVertexBuffer() {
  return vertexBuffer;
}
