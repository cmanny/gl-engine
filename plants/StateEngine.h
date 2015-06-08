#ifndef STATEENGINE_H
#define STATEENGINE_H

#include "Engine.h"
#include "GameState.h"

/**
 * The state engine derives from the abstract Engine class and manages the current state of the game
 */

class StateEngine: public Engine {
    GameState* state;
    int nbFrames;
    double lastTime;

    public:
      StateEngine(int width, int height, int frameRate, string title);
      void setState(GameState* state);
      void update(double);
      void setWindowFPS();
};

#endif
