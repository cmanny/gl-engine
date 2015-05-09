#include "StateEngine.h"
#include "RunningState.h"

// Constructor
StateEngine::StateEngine(int width, int height, int frameRate, string title) : 
  Engine(width, height, frameRate, title) {
    this->state = new RunningState();
}

// Set game state
void StateEngine::setState(GameState* state) {
  this->state->dispose();
  this->state = state;
}

// Override update method
void StateEngine::update(double delta) {
  if(state != NULL)
    state->update(delta);
}

// Override render method
