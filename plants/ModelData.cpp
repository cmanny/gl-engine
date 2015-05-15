#include "ModelData.h"
#include <common/texture.hpp>
#include <common/vboindexer.hpp>

ModelData::ModelData(){
  verticies = new VertexData<glm::vec3>(GL_ARRAY_BUFFER);
  uvs = new VertexData<glm::vec2>(GL_ARRAY_BUFFER);
  normals = new VertexData<glm::vec3>(GL_ARRAY_BUFFER);
  colours = new VertexData<glm::vec3>(GL_ARRAY_BUFFER);
  indices = new VertexData<GLuint>(GL_ELEMENT_ARRAY_BUFFER);
}

void ModelData::buildVBOIndex(){
  vector<glm::vec3>* indexed_verticies = new VertexData<glm::vec3>(GL_ARRAY_BUFFER);
  vector<glm::vec2>* indexed_uvs = new VertexData<glm::vec2>(GL_ARRAY_BUFFER);
  vector<glm::vec3>* indexed_normals = new VertexData<glm::vec3>(GL_ARRAY_BUFFER);
  indexVBO(vertices, uvs, normals, indices, indexed_vertices, indexed_uvs, indexed_normals);
}

void ModelData::loadTexture(std::string str){
  textureID = loadBMP_custom(str.c_str());
}

GLuint ModelData::getTexture(){
  return textureID;
}

VertexData<glm::vec3>* ModelData::getVerticies(){
  return verticies;
}

VertexData<glm::vec2>* ModelData::getUVs(){
  return uvs;
}

VertexData<glm::vec3>* ModelData::getNormals(){
  return normals;
}

VertexData<glm::vec3>* ModelData::getColours(){
  return colours;
}

VertexData<GLuint>* ModelData::getIndices(){
  return indices;
}

