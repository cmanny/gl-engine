#include <GL/glew.h>
#include <algorithm>
class VertexData {
  private:
    GLfloat* vertexData;
    GLuint* vertexBuffer;
    int size;

  public:
    VertexData();
    ~VertexData();

    GLfloat* getVertexData();
    GLuint* getVertexBuffer();

    void setVertexData(GLfloat* vertexData, int size);
    void refreshBuffer();
};
