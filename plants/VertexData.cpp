#include "VertexData.h"

// Constructor
VertexData::VertexData() {
  vertexBuffer = new GLuint;
  vertexData = 0;
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
  this->vertexData = new GLfloat[size];
  std::copy(vertexData, vertexData+size, this->vertexData);
  this->size = size;
  refreshBuffer();
}

int VertexData::numVerts(){
  return size/3;
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
