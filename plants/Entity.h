#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <vector>

class Entity {
  std::vector<GLfloat*> *vertexData;
  GLuint* vertexBuffer;

  public:
    Entity(std::vector<GLfloat*> *vertexData);
    virtual void update(double delta)=0;

    // Accessor methods
    std::vector<GLfloat*>* getVertexData();
    GLuint* getVertexBuffer();

    // Mutator methods
    void setVertexData(std::vector<GLfloat*>* vertexData);
};

#endif
