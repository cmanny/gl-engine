#ifndef MODELDATA_H
#define MODELDATA_H
#include "VertexData.h"
#include <string>

class ModelData {
  private:
    VertexData<glm::vec3>* verticies, * indexed_verticies,
                         * normals, * indexed_normals,
                         * colours, * indexed_colours;
    VertexData<glm::vec2>* uvs;
    VertexData<GLuint>* indices;
    GLuint textureID;

  public:
    ModelData();

    void loadTexture(std::string);
    GLuint getTexture();
    void buildVBOIndex();

    VertexData<glm::vec3>* getVerticies();
    VertexData<glm::vec2>* getUVs();
    VertexData<glm::vec3>* getNormals();
    VertexData<glm::vec3>* getColours();
    VertexData<GLuint>* getIndices();
};

#endif
