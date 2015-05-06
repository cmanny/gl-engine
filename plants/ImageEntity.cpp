#include "ImageEntity.h"
#include "Entity.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

// Constructor
ImageEntity::ImageEntity(GLuint* image, double x, double y, int width, int height) : Entity(x, y, width, height)
{
  this->image = image;
}

// Get entity image
GLuint* ImageEntity::getImage() {
  return image;
} 

// Set entity image
void ImageEntity::setImage(GLuint* image) {
  this->image = image;
}


