#include "Renderer.h"

Renderer* Renderer::instance = 0;

// Constructor
Renderer::Renderer(int scrW, int scrH){
  std::cout << "Renderer init\n";
  this->screenW = scrW;
  this->screenH = scrH;
  
  // Dark blue background
  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // Setup VAO (Vertex Array Object)
}

// Set entity render list
void Renderer::setEntities(vector<Entity*>* entities){
  this->entities = entities;
}

// Render entities
void Renderer::draw(){
 
  // Clear the screen
  glClear( GL_COLOR_BUFFER_BIT );
      
  // Use our shader
  glUseProgram(programID);
  
  // Enable drawing of vertex arrays
  glEnableVertexAttribArray(0);

  // Render each entity
  for(auto e = entities->begin(); e != entities->end(); e++){
    glBindBuffer(GL_ARRAY_BUFFER, *((*e)->getVertexBuffer()));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
    
  }
  // Disable drawing of arrays
  glDisableVertexAttribArray(0);
}

// Initialise renderer
void Renderer::init(int width, int height) {
  instance = new Renderer(width, height);
}

// Get renderer instance
Renderer* Renderer::getInstance() {
  return instance;
}


