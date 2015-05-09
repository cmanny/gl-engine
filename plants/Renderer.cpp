#include "Renderer.h"

// Constructor
Renderer::Renderer(int scrW, int scrH){
  std::cout << "Renderer init\n";
  this->screenW = scrW;
  this->screenH = scrH;
  
  // Dark blue background
  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);
  programID = LoadShaders( "shaders/SimpleTransform.vertexshader", "shaders/SingleColour.fragmentshader" );
  GLuint mvpMatID = glGetUniformLocation(programID, "MVP");

  projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
  view = glm::lookAt(
    glm::vec3(4,3,3), 
    glm::vec3(0,0,0), 
    glm::vec3(0,1,0)
    );
  model = glm::mat4(1.0f);
  mvp = projection*view*model;
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
  glUniformMatrix4fv(mvpMatID, 1, GL_FALSE, &mvp[0][0]);
  // Enable drawing of vertex arrays
  glEnableVertexAttribArray(0);
  for(auto e = entities->begin(); e != entities->end(); e++){
    glBindBuffer(GL_ARRAY_BUFFER, *(*e)->getVertexBuffer());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
    
  }
  glDisableVertexAttribArray(0);
}

