#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Renderer.h"
#include "EventManager.h"

class GameState {
  protected:
    EventManager* evtmgr;
    Renderer* renderer;
  
  public:
    GameState(EventManager* evtmgr, Renderer* renderer);
    virtual void init() = 0;
    virtual GameState* update(double delta) = 0;
    virtual void dispose() = 0;
};

#endif
