#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "GameState.h"


class MenuState : public GameState {

  public:
    void init();
    GameState* update(double delta);
    void dispose();
};

#endif /* MENUSTATE_H */
