#ifndef MODELDATA_H
#define MODELDATA_H
#include "VertexData.h"


class ModelData {
  private:
    VertexData<GLfloat>* verticies,
                       * uvs,
                       * normals,
                       * colours;
    VertexData<GLuint>* indices;

  public:
    ModelData();

    VertexData<GLfloat>* getVerticies();
    VertexData<GLfloat>* getUVs();
    VertexData<GLfloat>* getNormals();
    VertexData<GLfloat>* getColours();
    VertexData<GLuint>* getIndices();
};

#endif
