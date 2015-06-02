#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include <iostream>

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

#include <tbb/compat/thread>
#include <tbb/atomic.h>
#include <thread>

#include "EventManager.h"
#include "Camera.h"
#include "Renderer.h"

using namespace glm;
using namespace std;

class Engine {
  protected:
    EventManager* evtmgr;
    Renderer* renderer;
    GLFWwindow* window; 
    Camera* camera;

  private:  
    int width, 
        height, 
        frameRate, 
        desktopWidth, 
        desktopHeight;
    bool fullscreen; 
    string title;
    
    tbb::atomic<bool> running;
    
    void callback(Event evt);

  public:
    Engine(int _width, int _height, int _frameRate, string _title);
    void start();
    virtual void update(double delta) = 0;
};

#endif
