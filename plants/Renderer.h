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

/**
 * The Renderer class is reponsible for the graphical part of the system and runs in it's own thread
 * It also handles all calls to OpenGL as they can only be done in one thread at a time, so they are done in only this one for simplicity
 * The renderer will run in an infinite loop taking and executing commands from a concurrently safe queue.
 */

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
              model,
              mvp,
              camView;

    
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
