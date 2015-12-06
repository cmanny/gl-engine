#ifndef SPHERE_H
#define SPHERE_H

#include "Entity.h"
#include <iostream>
#include <string>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define M_PI 3.14159265358979323846264338327950288f

class Sphere : public Entity {
  private:
    int detail;
  public:
    Sphere(GLfloat, std::string);
    void update(double);
};
#endif
