#include "Entity.h"

// Constructor
Entity::Entity() {
  data = new VertexData();
}

// Destructor
Entity::~Entity() {
  delete data;
}

// Get vertex data
VertexData* Entity::getData() {
  return data;
}

// Set x pos
void Entity::setX(double x) {
  this->x = x;
}

// Set y pos
void Entity::setY(double y) {
  this->y = y;
}

// Increment x pos
void Entity::incX(double i) {
  x += i;
}

// Increment y pos
void Entity::incY(double i) {
  y += i;
}

// Return x pos
double Entity::getX() {
  return x;
}

// Return y pos
double Entity::getY() {
  return y;
}
