#include "RunningState.h"
#include "Scene.h"

// Constructor
RunningState::RunningState() {
  // TODO: Set start scene
}

// Update game
void RunningState::update(double delta) {
 
  // Update current scene
  if(scene != 0)
    scene->update(delta);
}

// Free resources
void RunningState::dispose() {
  scene->dispose();
}
