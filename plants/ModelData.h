#ifndef MODELDATA_H
#define MODELDATA_H
#include "VertexData.h"


class ModelData {
  private:
    VertexData* verticies,
              * uvs,
              * normals;
  public:
    ModelData();

    VertexData* getVerticies();
    VertexData* getUVs();
    VertexData* getNormals();
};

#endif
