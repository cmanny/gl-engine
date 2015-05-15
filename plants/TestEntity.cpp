#include "TestEntity.h"

// Constructor
TestEntity::TestEntity(){
    GLfloat verticies[] = {
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     0.0f,  1.0f, 0.0f,
    };
    getModel()->getVerticies()->setData(verticies, 9);
    lastTime = glfwGetTime(); 
}

// Override update method
void TestEntity::update(double delta) {
  // Do nothing... just chilling...
  
  
  if(true){
    
    rotate(8.0f);
    lastTime = glfwGetTime();
  }
}
