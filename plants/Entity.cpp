#include "Entity.h"

// Constructor
Entity::Entity() {
  data = new VertexData();
  model = glm::mat4(1.0f);
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

void Entity::move(double x, double y, double z){
  this->x = x;
  this->y = y;
  this->z = z;
  model = glm::translate(model, glm::vec3(x, y, z));
}

void Entity::rotate(float angle){
  model = glm::rotate(model, angle, rotationAxes);
}

glm::mat4 Entity::getModel(){
  return model;
}

void Entity::setShader(GLuint* shader) {
  this->shader = shader;
}

GLuint* Entity::getShader() {
  return shader;
}
