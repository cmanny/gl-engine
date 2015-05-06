#ifndef ANIMATEDENTITY
#define ANIMATEDENTITY

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <vector>

#include "ImageEntity.h"

using namespace std;

class AnimatedEntity : public ImageEntity {
    std::vector<GLuint*> *frames;
    int offset;
    int delay;
    double lastFrameTime;

    public:
      AnimatedEntity(std::vector<GLuint*> *frames, double x, double y, int width, int height, int offset, int delay);

      void update(double delta);
      std::vector<GLuint*> *getFrames();
      GLuint* getFrame(int offset);  
      void setFrames(vector<GLuint*>* frames);
};

#endif
