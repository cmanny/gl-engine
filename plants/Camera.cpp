#include "Camera.h"

Camera::Camera(EventManager* evtmgr){
  this->evtmgr = evtmgr;
}

void Camera::init(int x, int y, int z){
  evtmgr->enableCallback(makeCallback(this, EVT_MOUSESCROLL, (EvtCallback) &Camera::scrollCallback));
  evtmgr->enableCallback(makeCallback(this, EVT_KEY, (EvtCallback) &Camera::keyCallback));
  eyeX = x;
  eyeY = y;
  eyeZ = z;
  centreX = centreY = centreZ = 0;
}

glm::mat4 Camera::view(){
  return glm::lookAt(
    glm::vec3(eyeX, eyeY, eyeZ),
    glm::vec3(centreX, centreY, centreZ),
    glm::vec3(0, 1, 0)
    );
}

void Camera::scrollCallback(Event evt){
  eyeZ += evt.data[1];
}

void Camera::keyCallback(Event evt){
  int key = evt.data[0];
  int scancode = evt.data[1];
  int action = evt.data[2];
  int mods = evt.data[3];
  
  switch(action){
    case GLFW_REPEAT:
    case GLFW_PRESS:
      switch(key){
        case GLFW_KEY_A: centreX -= 0.2; break;
        case GLFW_KEY_D: centreX += 0.2; break;
        case GLFW_KEY_W: centreY += 0.2; break;
        case GLFW_KEY_S: centreY -= 0.2; break;
      }
    break;
    case GLFW_RELEASE: break;
  }
       
}
