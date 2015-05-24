#ifndef TERRAIN_H
#define TERRAIN_H
#include "Entity.h"
#include "FFT.h"
#include <iostream>
#include <unordered_map>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <random>

class Terrain : public Entity {
  private:
    int detail;
    GLfloat w, h;
    std::default_random_engine rEngine;
    std::normal_distribution<GLfloat> distribution;

  public:
    Terrain(GLfloat w,GLfloat h, std::string texture);
    void generate(int);
    void update(double){};
    void printMesh(Complex*, int);
};

#endif /* TERRAIN_H */
