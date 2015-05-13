#ifndef RENDERER_H
#define RENDERER_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <vector>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <common/shader.hpp>
#include "Entity.h"
#include "Camera.h"

using namespace std;

class Renderer {
  private:
    GLFWwindow* window;
    vector<Entity*>* entities;
    int screenW, screenH;
    GLuint VertexArrayID,  
           vertexbuffer;
    glm::mat4 projection,
              view,
              model,
              mvp;
    Camera* camera;

  public:
    Renderer(GLFWwindow* w, EventManager*, int,int);
    void addEntity(Entity* entity);
    void draw();
    Camera* getCamera(); 
};
#endif
