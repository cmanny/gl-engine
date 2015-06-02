#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <tbb/spin_mutex.h>
#include <tbb/atomic.h>
#include <tbb/concurrent_vector.h>

#include "Entity.h"
#include "Camera.h"
#include "GLCache.h"

using namespace std;

class Renderer {
  private:
    GLFWwindow* window;
    Camera* camera;
    
    tbb::concurrent_vector<Entity*> entities;
    
    int screenW, screenH;
    tbb::atomic<bool>* running;
    
    GLuint VertexArrayID,  
           vertexbuffer;
    glm::mat4 projection,
              view,
              model,
              mvp;

    
    GLCache cache;
    void initObjects();
    void initOpenGL();
    void draw();

  public:
    Renderer(GLFWwindow* w, Camera*, int,int, tbb::atomic<bool>*);
    void addEntity(Entity* entity);
    Camera* getCamera();
    //Thread operator functor
    void operator()();
};
#endif
