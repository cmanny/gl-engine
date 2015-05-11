#include <GL/glew.h>

class VertexData {
  private:
    GLfloat* vertexData;
    GLuint* vertexBuffer;
    int size;

  public:
    VertexData(int);
    ~VertexData();

    GLfloat* getVertexData();
    GLuint* getVertexBuffer();

    void setVertexData(GLfloat* vertexData, int size);
    void refreshBuffer();
};
