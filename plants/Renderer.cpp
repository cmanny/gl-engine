#include "Renderer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include "Entity.h"
#include <vector>

// Constructor
Renderer::Renderer(int scrW, int scrH){
  this->screenW = scrW;
  this->screenH = scrH;
  
  // Setup VAO (Vertex Array Object)
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);
}

// Set entity render list
void Renderer::setEntities(vector<Entity*>* entities){
  this->entities = entities;
}

// Render entities
void Renderer::draw(){
  
  // Enable drawing of vertex arrays
  glEnableVertexAttribArray(0);

  // Render each entity
  for(auto e = entities->begin(); e != entities->end(); e++){
    glBindBuffer(GL_ARRAY_BUFFER, *(*e)->getVertexBuffer());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  }

  // Disable drawing of arrays
  glDisableVertexAttribArray(0);
}

// Initialise renderer
static void Renderer::init(int width, int height) {
  instance = new Renderer(width, height);
}

// Get renderer instance
Renderer* Renderer::getInstance() {
  return &instance;
}


