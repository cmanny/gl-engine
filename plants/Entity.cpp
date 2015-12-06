#include "Entity.h"
#include <iostream>
// Constructor
Entity::Entity() {
  std::cout << "new vertex data\n";
  model = new ModelData();
  posMat = glm::mat4(1.0f);
  rotationAxes = glm::vec3(1.0f,0.0f,0.0f);
  x = y = z = rotation = 0;
  shader = -1;
}

// Destructor
Entity::~Entity() {
  delete model;
}

ModelData* Entity::getModel(){
  return model;
}
// Get vertex data

void Entity::move(double x, double y, double z){
  this->x = x;
  this->y = y;
  this->z = z;
  posMat = glm::translate(posMat, glm::vec3(x, y, z));
}

void Entity::rotate(float angle){
  posMat = glm::rotate(posMat, angle, rotationAxes);
}

void Entity::scale(float x, float y, float z){
  posMat = glm::scale(posMat, glm::vec3(x,y,z));
}

glm::mat4 Entity::getPos(){
  return posMat;
}

void Entity::setShader(GLuint shader) {
  this->shader = shader;
}

GLuint Entity::getShader() {
  return shader;
}

// Get entity x co-ordinate
double Entity::getX() {
  return x;
}

// Get entity y co-ordinate
double Entity::getY() {
  return y;
}

// Get entity z co-ordinate
double Entity::getZ() {
  return z;
}
