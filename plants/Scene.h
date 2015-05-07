#ifndef SCENE_H
#define SCENE_H

#include "RunningState.h"

class RunningState;

class Scene {
  RunningState* state;

  public:
    Scene(RunningState* state);
    virtual void update(double delta) = 0;
    virtual void dispose() = 0;
};


#endif
