#ifndef RUNNINGSTATE_H
#define RUNNINGSTATE_H

#include "GameState.h"
#include "Scene.h"

class Scene;

class RunningState : public GameState {
  Scene* scene = 0;

  public:
    RunningState();
    void update(double delta);
    void dispose();
};

#endif
