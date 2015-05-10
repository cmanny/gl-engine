#include <GL/glew.h>

class VertexData {
  private:
    GLfloat* vertexData;
    GLuint* vertexBuffer;
  public:
    VertexData();
    ~VertexData();
    GLfloat* vertexData();
    GLuint* vertexBuffer();
};
