#ifndef SPHERE_H
#define SPHERE_H

#include "Entity.h"

#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Sphere : public Entity {
  private:
    int detail;
  public:
    Sphere(int);
    void update(double);
};
#endif
