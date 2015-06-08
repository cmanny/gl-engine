#include "StateEngine.h"
#include "RunningState.h"
#include "LoadingState.h"

/**
 * Initialisation routine */
StateEngine::StateEngine(int width, int height, int frameRate, string title) : 
  Engine(width, height, frameRate, title) {
    this->state = new LoadingState(evtmgr, renderer);
    this->state->init();

    nbFrames = 0;
    lastTime = 0;
}

/**
 * When setting a new state, we call the dispose method of the old state so that it can manage
 * destruction of held objects 
 */
void StateEngine::setState(GameState* state) {
  this->state->dispose();
  this->state = state;
}

/**
 * Overriding the pure virtual method, the update function simply evaluates the state returned by
 * the current state, and if it is not the same, we set the new state running, and call the update method
 */
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

/**
 * Shows a simple FPS counter in the title bar 
 */
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
