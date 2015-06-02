#ifndef CAMERA_H
#define CAMERA_H
#include "EventManager.h"

#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

#include <tbb/mutex.h>
#include <thread>

class Camera {
  private:
    double eyeX, eyeY, eyeZ,
        centreX, centreY, centreZ,
        moveVelX, moveVelY, moveVelZ;

    glm::mat4 viewMat;
    
    bool moveNorth, moveEast, moveSouth, moveWest, rotNorth, rotSouth;
    EventManager* evtmgr;
    
    void scrollCallback(Event);
    void keyCallback(Event);

    tbb::mutex mutex;

  public:
    Camera(EventManager* evtmgr);
    glm::vec3 getPos();
    void init(int,int,int);
    void update(double delta);
    glm::mat4 view();
};

#endif
