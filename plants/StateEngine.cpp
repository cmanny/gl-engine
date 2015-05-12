#include "StateEngine.h"
#include "RunningState.h"

// Constructor
StateEngine::StateEngine(int width, int height, int frameRate, string title) : 
  Engine(width, height, frameRate, title) {
    this->state = new RunningState(evtmgr, renderer);
    this->state->init();

    nbFrames = 0;
    lastTime = 0;
}

// Set game state
void StateEngine::setState(GameState* state) {
  this->state->dispose();
  this->state = state;
}

// Override update method
void StateEngine::update(double delta) {
 
  // Update state 
  if(state != NULL) {
    GameState* result = state->update(delta);

    // Handle state update
    if(result != state && result != 0)
      setState(result);
  }
  setWindowFPS();
}

// Update FPS counter
void StateEngine::setWindowFPS ()
{
    double currentTime = glfwGetTime ();
    nbFrames++;

    if(currentTime - lastTime >= 1.0 ){ 
      char title [256];
      title [255] = '\0';

      snprintf ( title, 255,"%s %s - [FPS: %3.2f]","Plants", "0.0.1", (float)nbFrames );

      glfwSetWindowTitle (window, title);

      nbFrames = 0;
      lastTime += 1.0;
    }
}
