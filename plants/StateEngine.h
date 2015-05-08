#ifndef STATEENGINE_H
#define STATEENGINE_H

#include "Engine.h"
#include "GameState.h"


class StateEngine: public Engine {
    GameState* state;
    
    public:
      StateEngine(GameState* state, int width, int height, int frameRate, string title);
      void setState(GameState* state);
      void update(double);
};

#endif
