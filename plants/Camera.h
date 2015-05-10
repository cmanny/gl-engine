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
        centreX, centreY, centreZ,
        moveVelX, moveVelY, moveVelZ;
    
    bool moveNorth, moveEast, moveSouth, moveWest;    
    EventManager* evtmgr;
    
    void scrollCallback(Event);
    void keyCallback(Event);

  public:
    Camera(EventManager* evtmgr);
    void init(int,int,int);
    void update(double delta);
    glm::mat4 view();
};

#endif
