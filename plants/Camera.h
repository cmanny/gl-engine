#ifndef CAMERA_H
#define CAMERA_H
#include "EventManager.h"
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class Camera {
  private:
    double eyeX, eyeY, eyeZ,
        centreX, centreY, centreZ;
    
    EventManager* evtmgr;
    
    void scrollCallback(Event);
    void keyCallback(Event);

  public:
    Camera(EventManager* evtmgr);
    void init(int,int,int);
    glm::mat4 view();
    
};

#endif
