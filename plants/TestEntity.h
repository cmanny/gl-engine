#ifndef TESTENTITY_H
#define TESTENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include "Entity.h"

class TestEntity : public Entity {
  private:
    double lastTime;
  public:
    TestEntity();
    void update(double delta);
};
#endif
