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
  //
}
