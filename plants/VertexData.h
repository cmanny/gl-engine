#include <GL/glew.h>

class VertexData {
  private:
    GLfloat* vertexData;
    GLuint* vertexBuffer;

  public:
    VertexData();
    ~VertexData();

    GLfloat* getVertexData();
    GLuint* getVertexBuffer();

    void setVertexData(GLfloat* vertexData);
    void refreshBuffer();
};
