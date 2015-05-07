#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "GameState.h"


class MenuState : public GameState {

  public:
    void update(double delta);
    void dispose();
};

#endif /* MENUSTATE_H */
