#include "Renderer.h"
#include "AssetManager.h"

// Constructor
Renderer::Renderer(GLFWwindow* w,EventManager* evtmgr, int scrW, int scrH){
  std::cout << "Renderer init\n";
  this->screenW = scrW;
  this->screenH = scrH;
  this->window = w;  
  camera = new Camera(evtmgr);
  camera->init(0,0,64);

  // Dark blue background
  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

  // Setup VAO
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID); 
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  // Setup perspective
  projection = glm::perspective(20.0f, 4.0f / 3.0f, 0.1f, 1000.0f);
  view = glm::lookAt(
    glm::vec3(0,0,16), 
    glm::vec3(0,0,0), 
    glm::vec3(0,1,0)
    );

  model = glm::mat4(1.0f);
  mvp = projection*view*model; 
  entities = 0;
} 
// Set entity render list
void Renderer::setEntities(vector<Entity*>* entities){
  this->entities = entities;
}

// Render entities
void Renderer::draw(){
  // Clear the screen
  if(entities == 0){
    std::cout << "Entities not initialised";
    return;
  }
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Enable drawing of vertex arrays
  for(auto e = entities->begin(); e != entities->end(); e++){
    mvp = projection * camera->view() * (*e)->getModel();
    
    GLuint* shader = (*e)->getShader();
    if(*shader == 0) 
      shader = AssetManager::assets->DEFAULT_SHADER;

    GLuint mvpMatID = glGetUniformLocation(*shader, "MVP");
    glUseProgram(*shader);

    glUniformMatrix4fv(mvpMatID, 1, GL_FALSE, &mvp[0][0]);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, *(*e)->getData()->getVertexBuffer());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, *(*e)->getColour()->getVertexBuffer());
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);    

    glDrawArrays(GL_TRIANGLES, 0, (*e)->getData()->numVerts());    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
  }

}

// Return camera instance
Camera* Renderer::getCamera() {
  return camera;
}
