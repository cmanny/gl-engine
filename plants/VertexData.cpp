#include "VertexData.h"

// Constructor
VertexData::VertexData() {
  vertexData = new GLfloat[9];
  this->size = size;
  refreshBuffer();
}

// Destructor
VertexData::~VertexData() {
 delete vertexData;
 delete vertexBuffer;
}

// Get vertex data
GLfloat* VertexData::getVertexData() {
  return vertexData;
}

// Get vertex buffer
GLuint* VertexData::getVertexBuffer() {
  return vertexBuffer;
}

// Set vertex data
void VertexData::setVertexData(GLfloat* vertexData, int size) {
  this->vertexData = vertexData;
  this->size = size;
  refreshBuffer();
}

// Rebuild vertex buffer
void VertexData::refreshBuffer() {

  // Generate & bind vertex buffer
  glGenBuffers(1, vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, *vertexBuffer);
      
  // Pass updated vertices to OpenGL.
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*size, 
      vertexData, GL_STATIC_DRAW);
}
