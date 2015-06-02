#include "Renderer.h"

// Constructor
Renderer::Renderer(GLFWwindow* w, Camera* c, int scrW, int scrH, tbb::atomic<bool>* running){
  std::cout << "Renderer init\n";
  this->screenW = scrW;
  this->screenH = scrH;
  this->window = w; 
  this->camera = c;
  this->running = running; 
  //entities = new tbb::concurrent_vector<Entity*>();
} 

// Add entity
void Renderer::addEntity(Entity* entity) {
  entities.push_back(entity);
}

void Renderer::initObjects(){  
  camera->init(64,32,600);
    // Setup perspective
  projection = glm::perspective(20.0f, 4.0f / 3.0f, 0.1f, 1000.0f);
  view = glm::lookAt(
    glm::vec3(0,0,16), 
    glm::vec3(0,0,0), 
    glm::vec3(0,1,0)
  );

  model = glm::mat4(1.0f);
  mvp = projection*view*model; 
  
  cache.loadAssets();
  
  std::cout << "Renderer::initObjects()\n";
}

void Renderer::initOpenGL(){
  glfwMakeContextCurrent(window);
  glewExperimental=true;
  if (glewInit() != GLEW_OK) {
    cerr << "Error initializing GLEW.\n";
    exit(-1);
  }
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID); 
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
  std::cout << "Renderer::initOpenGL\n";
}

void Renderer::draw(){
  glm::mat4 camView = camera->view();
  for(auto &e : entities){
    if(!e->getModel()->isCurrent()){
      e->getModel()->refreshBuffers();
      e->getModel()->setTextureID(cache.getTextureID(e->getModel()->getTexturePath()));
      e->getModel()->makeCurrent();
    }
    GLuint LightID, TextureID, programID;
    programID = e->getShader();
    if(programID == -1)
      programID = cache.DEFAULT_SHADER;
    glUseProgram(programID);
    LightID = cache.getUniformLocation(programID, "LightPosition_worldspace");
    TextureID  = cache.getUniformLocation(programID, "myTextureSampler"); 
    mvp = projection * camView * e->getPos();
    GLuint mvpMatID = cache.getUniformLocation(programID, "MVP");
    GLuint ViewMatrixID = cache.getUniformLocation(programID, "V");
    GLuint ModelMatrixID = cache.getUniformLocation(programID, "M");
    
    glUniformMatrix4fv(mvpMatID, 1, GL_FALSE, &mvp[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &e->getPos()[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &camView[0][0]);
     
    glm::vec3 lightPos = glm::vec3(160,160,64);;
    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);   
    
    GLuint texture = e->getModel()->getTexture();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, e->getModel()->getTexture());
    glUniform1i(TextureID, 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, *e->getModel()->getVertices()->getBuffer());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, *e->getModel()->getUVs()->getBuffer());
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);    
    
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, *e->getModel()->getNormals()->getBuffer());
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *e->getModel()->getIndices()->getBuffer());

    glDrawElements(GL_TRIANGLES, e->getModel()->getIndices()->numVerts(), GL_UNSIGNED_INT, (void*)0); 
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
  }
}

// Renderer thread function
void Renderer::operator()(){
  initOpenGL();
  initObjects();
  while(*running){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw();    
    glfwSwapBuffers(window);
  } 
}

Camera* Renderer::getCamera(){
  return camera;
}
// Return camera instance
