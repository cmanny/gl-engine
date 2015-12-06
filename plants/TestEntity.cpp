#include "TestEntity.h"

// Constructor
TestEntity::TestEntity(){
    //getModel()->getVerticies()->setData(verticies, 9);
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
