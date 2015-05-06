#ifndef RUNNINGSTATE
#define RUNNINGSTATE

#include "GameState.h"

class RunningState : public GameState {
  public:
    void update(double delta);
    void dispose();
};

#endif
