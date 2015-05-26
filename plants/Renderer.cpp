#include "Renderer.h"
#include "AssetManager.h"

// Constructor
Renderer::Renderer(GLFWwindow* w,EventManager* evtmgr, int scrW, int scrH){
  std::cout << "Renderer init\n";
  this->screenW = scrW;
  this->screenH = scrH;
  this->window = w;  
  camera = new Camera(evtmgr);
  camera->init(64,64,200);

  // Dark blue background
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  // Setup VAO
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID); 
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
  // Setup perspective
  projection = glm::perspective(20.0f, 4.0f / 3.0f, 0.1f, 1000.0f);
  view = glm::lookAt(
    glm::vec3(0,0,16), 
    glm::vec3(0,0,0), 
    glm::vec3(0,1,0)
    );

  model = glm::mat4(1.0f);
  mvp = projection*view*model; 
  entities = new vector<Entity*>();

  } 
// Set entity render list

// Add entity
void Renderer::addEntity(Entity* entity) {
  entities->push_back(entity);
}

// Render entities
void Renderer::draw(){
  // Clear the screen
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for(auto e = entities->begin(); e != entities->end(); e++){

    GLuint LightID, TextureID, programID;
    programID = (*e)->getShader();
    if(programID == -1)
      programID = AssetManager::assets->DEFAULT_SHADER;
    glUseProgram(programID);
    LightID = glGetUniformLocation(programID, "LightPosition_worldspace");
    TextureID  = glGetUniformLocation(programID, "myTextureSampler"); 

    mvp = projection * camera->view() * (*e)->getPos();
    GLuint mvpMatID = glGetUniformLocation(programID, "MVP");
    GLuint ViewMatrixID = glGetUniformLocation(programID, "V");
    GLuint ModelMatrixID = glGetUniformLocation(programID, "M");
    
    glUniformMatrix4fv(mvpMatID, 1, GL_FALSE, &mvp[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &(*e)->getPos()[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &camera->view()[0][0]);
     
    glm::vec3 lightPos = glm::vec3(64,64,32);;
    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);   
    
    GLuint texture = (*e)->getModel()->getTexture();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, (*e)->getModel()->getTexture());
    glUniform1i(TextureID, 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, *(*e)->getModel()->getVertices()->getBuffer());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, *(*e)->getModel()->getUVs()->getBuffer());
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);    
    
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, *(*e)->getModel()->getNormals()->getBuffer());
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *(*e)->getModel()->getIndices()->getBuffer());

    glDrawElements(GL_TRIANGLES, (*e)->getModel()->getIndices()->numVerts(), GL_UNSIGNED_INT, (void*)0); 
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
  }
}

// Return camera instance
Camera* Renderer::getCamera() {
  return camera;
}
