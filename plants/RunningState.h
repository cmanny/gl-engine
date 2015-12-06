#ifndef RUNNINGSTATE_H
#define RUNNINGSTATE_H

#include "GameState.h"
#include "Scene.h"
#include "Renderer.h"
#include "EventManager.h"

#include <vector>
#include <tbb/concurrent_queue.h>
#include <tbb/task_group.h>

class Scene;
class Entity;

class RunningState : public GameState {
  private:
    Scene* scene = 0;
    std::vector<Entity*> entities;
    tbb::concurrent_queue<Entity*> newEntities;
    tbb::task_group async;

  public:
    RunningState(EventManager*, Renderer*);
    void init();
    GameState* update(double delta);
    void dispose();
};

#endif
