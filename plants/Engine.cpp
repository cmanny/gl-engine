#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

#include "Engine.h"
#include "AnimatedEntity.h"



using namespace glm;
using namespace std;

// Game engine constructor
Engine::Engine(int _width, int _height, int _frameRate, string _title) {
  width = _width;
  height = _height;
  frameRate = _frameRate;
  title = _title;
  fullscreen = false;
}

void Engine::callback(Event evt){
  if(evt.data[0] == GLFW_KEY_F11){
    int w = !fullscreen ? desktopWidth : width;
    int h = !fullscreen ? desktopHeight : height;
    fullscreen = !fullscreen;
    glfwSetWindowSize(window,w, h);
    glfwSetWindowPos(window,0, 0); 
  }else if(evt.data[0] == GLFW_KEY_ESCAPE){
    this->running = false;
  }

} 


// Start game engine
void Engine::start() {
  cout << "Starting Engine.\n";
  running = true; 

  // Initialise GLFW
  if(!glfwInit()) {
    cerr << "Error initializing GLFW.\n";
    exit(-1);
  }

  
  

  // Set OpenGL Window hints
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 


  // Open a window and create its OpenGL context 
  window = glfwCreateWindow( width, height, title.c_str(), NULL, NULL);
  if( window == NULL ){
      cerr << "Error creating GLFW window.\n";
      glfwTerminate();
      exit(-1);
  }
  
  
  // Initialise GLEW
  glfwMakeContextCurrent(window); 
  glewExperimental=true; // Needed in core profile
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Error initializing GLEW.\n");
    exit(-1);
  }
  
  const GLFWvidmode* desktopMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
  desktopHeight = desktopMode->height;
  desktopWidth = desktopMode->width;
    // Ensure capture of escape key
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  // Define start time
  double lastTime = glfwGetTime();
  EventManager evtmgr(window);
  evtmgr.enableCallback(makeCallback(this, EVT_KEY, (EvtCallback) &Engine::callback));

  // Main game loop
  do {
     
     // Calculate delta
     double currentTime = glfwGetTime();
     double delta = currentTime - lastTime;

     // Invoke sub-class functions
     update(delta);

     glfwSwapBuffers(window);
     glfwWaitEvents(); 
     cout << "Running:" << running;
    // glfwPollEvents();
  } 
  
  // Check if the ESC key was pressed or the window was closed
  while(running);
}










