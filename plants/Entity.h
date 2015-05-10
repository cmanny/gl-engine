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
  protected:
    GLfloat* vertexData = 0;
    void refreshBuffer();
  private:
    GLuint* vertexBuffer = 0;

  public:
    Entity();
    //~Entity();
    virtual void update(double delta)=0;

    // Accessor methods
    GLfloat* getVertexData();
    GLuint* getVertexBuffer();

    // Mutator methods
};

#endif
