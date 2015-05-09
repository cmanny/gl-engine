#include "TestEntity.h"
#include "Entity.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

// Constructor
TestEntity::TestEntity(){
    vertexData = new GLfloat[9];
    GLfloat jimData[] = {
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     0.0f,  1.0f, 0.0f,
    };
    std::copy(jimData,jimData+9,vertexData);
    refreshBuffer();
 
  // Do nothing. Just a test, so chill...
}

// Override update method
void TestEntity::update(double delta) {
  // Do nothing... just chilling...
}
