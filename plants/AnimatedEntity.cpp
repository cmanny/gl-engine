#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <vector>

#include "AnimatedEntity.h"
#include "ImageEntity.h"

// Constructor
AnimatedEntity::AnimatedEntity(std::vector<GLuint*> *frames, double x, double y, int width, int height, int offset, int delay) :
         ImageEntity(0, x, y, width, height)
{
    this->frames = frames;
    this->offset = offset;
    this->delay = delay;

    setImage(frames->at(0));
    lastFrameTime = -1;
}

// Update frames
void AnimatedEntity::update(double delta) {
  
  // Get current time
  double currentTime = glfwGetTime();
   
  // Start timer
  if(lastFrameTime == -1)
    lastFrameTime = currentTime;
  
  // Update frame
  else if(currentTime - lastFrameTime >= delay) {
    lastFrameTime = -1;

    if(++offset >= frames->size())
      offset = 0;

      setImage(frames->at(offset));
  }
}

// Get frames
vector<GLuint*>* AnimatedEntity::getFrames() {
  return frames;
}

// Set frames
void AnimatedEntity::setFrames(vector<GLuint*>* frames) {
  this->frames = frames;
}
