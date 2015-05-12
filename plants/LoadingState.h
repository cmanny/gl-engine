#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H

#include "GameState.h"

class LoadingState : GameState {
  public:
    void init();
    GameState* update(double delta);
    void dispose();
};

#endif
