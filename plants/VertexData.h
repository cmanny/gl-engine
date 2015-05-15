#include <GL/glew.h>
#include <algorithm>

template<class T>
class VertexData {
  private:
    T* data;
    GLuint* buffer;
    int size;

  public:
    VertexData();
    ~VertexData();

    T* getData();
    GLuint* getBuffer();

    void setData(T* vertexData, int size);
    void refreshBuffer();
    int numVerts();
};

#include "VertexData.tpp"
