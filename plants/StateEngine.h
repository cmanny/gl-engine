#ifndef STATEENGINE_H
#define STATEENGINE_H

#include "Engine.h"
#include "GameState.h"


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
