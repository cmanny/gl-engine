#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
  public:
    virtual void init() = 0;
    virtual GameState* update(double delta) = 0;
    virtual void dispose() = 0;
};

#endif
