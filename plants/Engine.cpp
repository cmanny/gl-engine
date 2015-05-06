#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

#include "Engine.h"

using namespace glm;
using namespace std;

// Game engine constructor
Engine::Engine(int _width, int _height, int _frameRate, string _title) {
  width = _width;
  height = _height;
  frameRate = _frameRate;
  title = _title;
}

// Start game engine
void Engine::start() {
  if(!running) {
    running = true; 

    // Initialise GLFW
    if(!glfwInit()) {
      fprintf(stderr, "Error initializing GLFW.\n");
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
        fprintf(stderr, "Error creating GLFW window.\n");
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

    // Ensure capture of escape key
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    // Main game loop
    do {
       
      // Check if game still running
      if(!running)
        break;

       // Setup VAO(Vertex Array Object)
       GLuint VertexArrayID;
       glGenVertexArrays(1, &VertexArrayID);
       glBindVertexArray(VertexArrayID);

       // Calculate delta
       double delta = 1.0; // TEMP****

       // Invoke sub-class functions
       update(delta);
       render();

       // Swap buffers
       glfwSwapBuffers(window);
       glfwPollEvents();
    } 
    
    // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
                            glfwWindowShouldClose(window) == 0 );
  }
}










