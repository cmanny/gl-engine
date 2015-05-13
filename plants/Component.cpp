#include "Component.h"

// Constructor
Component::Component(int width, int height) {
   this->width = width;
   this->height = height;
   this->leftx = x - (GLfloat)width/2.0f;
   this->rightx = x + (GLfloat)width/2.0f;
   this->topy = y + (GLfloat)height/2.0f;
   this->bottomy = y - (GLfloat)height/2.0f;
     
}

// Set component width
void Component::setWidth(int width) {
  this->width = width;
}

// Set component height
void Component::setHeight(int height) {
  this->height = height;
}

// Get component width
int Component::getWidth() {
  return width;
}

// Get component height
int Component::getHeight() {
  return height;
}

// Check if current component contains another
bool Component::contains(Component* component) {
  
  // Extract component data
  int x2 = component->getX();
  int y2 = component->getY();
  int width2 = component->getWidth();
  int height2 = component->getHeight();

  // Perform check
  if(x >= x2 && x + width <= x2 + width2) {
    if(y >= y2 && y + height <= y2 + height2)
      return true;
  }
  return false;
}

// Check if component contains given point
bool Component::contains(int x, int y) {
  if(x >= this->x && x <= this->x + width) {
   if(y >= this->y && y<= this->y + height)
     return true;
  } 
  return false;
}

// Check if component contains rectangle
bool Component::contains(int x, int y, int width, int height) {
  if(x >= this->x && x + width <= this->x + this->width) {
      if(y >= this->y && y + height <= this->y + this->height)
        return true;
  }
  return false;
}
