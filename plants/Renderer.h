#ifndef RENDERER_H
#define RENDERER_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include "Entity.h"
#include <vector>
#include <iostream>

using namespace glm;

#include <common/shader.hpp>
using namespace std;

class Renderer {
  private:
    vector<Entity*>* entities;
    int screenW, screenH;
    GLuint VertexArrayID, programID, vertexbuffer;

  public:
    Renderer(int,int);
    void setEntities(vector<Entity*>* entities);
    void draw(); 
};
#endif
