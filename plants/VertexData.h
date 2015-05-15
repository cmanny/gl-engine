#include <GL/glew.h>
#include <algorithm>
#include <vector>

template<class T>
class VertexData {
  private:
    std::vector<T>* data;
    GLuint* buffer;
    int bufferType;

  public:
    VertexData(int);
    ~VertexData();

    std::vector<T>* getData();
    GLuint* getBuffer();

    void setData(std::vector<T>* vertexData);
    void refreshBuffer();
    int numVerts();
};

#include "VertexData.tpp"
