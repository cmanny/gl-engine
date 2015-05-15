#include "ModelData.h"

ModelData::ModelData(){
  verticies = new VertexData<GLfloat>();
  uvs = new VertexData<GLfloat>();
  normals = new VertexData<GLfloat>();
  colours = new VertexData<GLfloat>();
  indices = new VertexData<GLuint>();
}

VertexData<GLfloat>* ModelData::getVerticies(){
  return verticies;
}

VertexData<GLfloat>* ModelData::getUVs(){
  return uvs;
}

VertexData<GLfloat>* ModelData::getNormals(){
  return normals;
}

VertexData<GLfloat>* ModelData::getColours(){
  return colours;
}

VertexData<GLuint>* ModelData::getIndices(){
  return indices;
}

