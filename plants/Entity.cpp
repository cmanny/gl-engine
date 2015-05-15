#include "Entity.h"
#include <iostream>
// Constructor
Entity::Entity() {
  std::cout << "new vertex data\n";
  data = new VertexData();
  colourData = new VertexData();
  posMat = glm::mat4(1.0f);
  rotationAxes = glm::vec3(1.0f,0.0f,1.0f);
  x = y = rotation = 0;
  shader = new GLuint;
  *shader = 0;
}

// Destructor
Entity::~Entity() {
  delete data;
}

// Get vertex data
VertexData* Entity::getData() {
  return data;
}

VertexData* Entity::getColour(){
  return colourData;
}

void Entity::move(double x, double y, double z){
  this->x = x;
  this->y = y;
  this->z = z;
  posMat = glm::translate(posMat, glm::vec3(x, y, z));
}

void Entity::rotate(float angle){
  posMat = glm::rotate(posMat, angle, rotationAxes);
}

glm::mat4 Entity::getPos(){
  return posMat;
}

void Entity::setShader(GLuint* shader) {
  this->shader = shader;
}

GLuint* Entity::getShader() {
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
