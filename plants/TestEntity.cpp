#include "TestEntity.h"

// Constructor
TestEntity::TestEntity(){
    GLfloat* _data = new GLfloat[9];
    GLfloat data[] = {
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     0.0f,  1.0f, 0.0f,
    };
    std::copy(data, data+9, _data);
    getData()->setVertexData(_data, 9);
    lastTime = glfwGetTime(); 
}

// Override update method
void TestEntity::update(double delta) {
  // Do nothing... just chilling...
  if(delta){
    rotate(2.0f*delta);
    lastTime = glfwGetTime();
  }
}
