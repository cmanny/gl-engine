#ifndef MODELDATA_H
#define MODELDATA_H
#include "VertexData.h"
#include <string>
#include <glm/glm.hpp>
#include <common/texture.hpp>

#include <tbb/atomic.h>

class ModelData {
  private:
    VertexData<glm::vec3>* vertices, * indexed_vertices,
                         * normals, * indexed_normals,
                         * colours, * indexed_colours;
    VertexData<glm::vec2>* uvs;
    VertexData<unsigned int>* indices;
    GLuint textureID;

    std::string texPath;

    tbb::atomic<bool> is_current;
  public:
    ModelData();

    tbb::atomic<bool> isCurrent();
    void makeCurrent();

    void loadTexture(std::string);
    void refreshBuffers();
    GLuint getTexture();
    std::string getTexturePath();
    void setTexturePath(std::string);
    void setTextureID(GLuint);
    void buildVBOIndex();

    VertexData<glm::vec3>* getVertices();
    VertexData<glm::vec2>* getUVs();
    VertexData<glm::vec3>* getNormals();
    VertexData<glm::vec3>* getColours();
    VertexData<unsigned int>* getIndices();
};

#endif
