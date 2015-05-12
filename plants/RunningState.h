#ifndef RUNNINGSTATE_H
#define RUNNINGSTATE_H

#include "GameState.h"
#include "Scene.h"
#include "Renderer.h"
#include "EventManager.h"
#include <vector>

class Scene;

class RunningState : public GameState {
  private:
    Scene* scene = 0;
    std::vector<Entity*>* entities = 0;

  public:
    RunningState(EventManager*, Renderer*);
    void init();
    GameState* update(double delta);
    void dispose();
};

#endif
