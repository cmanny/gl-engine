#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H

#include "GameState.h"
#include "EventManager.h"
#include "Renderer.h"

class LoadingState : public GameState {
  public:
    LoadingState(EventManager* evtmgr, Renderer* renderer);
    void init();
    GameState* update(double delta);
    void dispose();
};

#endif
