#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameState.h"
#include "EventManager.h"
#include "Renderer.h"
#include "ComponentManager.h"

class MenuState : public GameState {
  private:
    ComponentManager* manager;


  public:
    MenuState(EventManager* evtmgr, Renderer* renderer);
    void init();
    GameState* update(double delta);
    void dispose();
};

#endif /* MENUSTATE_H */
