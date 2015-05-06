#ifndef IMAGEENTITY
#define IMAGEENTITY

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

#include "Entity.h"

class ImageEntity : public Entity {
  GLuint* image;

  public:
    ImageEntity(GLuint* image, double x, double y, int width, int height);
    GLuint* getImage();
    void setImage(GLuint* image);
};

#endif
