#ifndef MODELDATA_H
#define MODELDATA_H
#include "VertexData.h"
#include <string>
#include <glm/glm.hpp>

class ModelData {
  private:
    VertexData<glm::vec3>* vertices, * indexed_vertices,
                         * normals, * indexed_normals,
                         * colours, * indexed_colours;
    VertexData<glm::vec2>* uvs;
    VertexData<unsigned int>* indices;
    GLuint textureID;

  public:
    ModelData();

    void loadTexture(std::string);
    GLuint getTexture();
    void buildVBOIndex();

    VertexData<glm::vec3>* getVertices();
    VertexData<glm::vec2>* getUVs();
    VertexData<glm::vec3>* getNormals();
    VertexData<glm::vec3>* getColours();
    VertexData<unsigned int>* getIndices();
};

#endif
