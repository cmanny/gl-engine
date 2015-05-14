#include "ModelData.h"

ModelData::ModelData(){
  verticies = new VertexData();
  uvs = new VertexData();
  normals = new VertexData();
}

VertexData* ModelData::getVerticies(){
  return verticies;
}

VertexData* ModelData::getUVs(){
  return uvs;
}

VertexData* ModelData::getNormals(){
  return normals;
}
