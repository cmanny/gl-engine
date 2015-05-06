#include "Entity.h"
#include <math.h>

// Constructor
Entity::Entity(int x, int y) {
  this->x = x;
  this->y = y;
}

Entity::Entity(int x, int y, int width, int height) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

// Return entity X co-ordinate
double Entity::getX() {
  return x;
}

// Return entity Y co-ordinate
double Entity::getY() {
  return y;
}

// Return entity width
int Entity::getWidth() {
  return width;
}

// Return entity height
int Entity::getHeight() {
  return height;
}

// Set entity x co-ordinate
void Entity::setX(double x) {
  this->x = x;
}

// Set entity y co-ordinate
void Entity::setY(double y) {
  this->y = y;
}

// Increment entity x co-ordinate
void Entity::incX(double i) {
  x += i;
}

// Increment entity y co-ordinate
void Entity::incY(double i) {
  y += i;
}

// Set entity width
void Entity::setWidth(int width) {
  this->width = width;
}

// Set entity height
void Entity::setHeight(int height) {
  this->height = height;
}

// Set entity position
void Entity::setPos(double x, double y) {
  this->x = x;
  this->y = y;
}

// Increment entity position
void Entity::incPos(double i, double j) {
  x += i;
  y += j;
}

// Set entity bounds
void Entity::setBounds(double x, double y, int width, int height) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
} 

// Get entity centre x co-ordinate
double Entity::getCentreX() {
  return x + width / 2;
}

// Get entity centre y co-ordinate
double Entity::getCentreY() {
  return y + height / 2;
}

// Get distance from entity
double Entity::getDist(Entity entity) {
  
  // Get entity centre pos
  double x1 = getCentreX();
  double y1 = getCentreY();

  double x2 = entity.getCentreX();
  double y2 = entity.getCentreY();

  // Calculate distance
  double distance = hypot(x1 - x2, y1 - y2);

  return distance;
}

























