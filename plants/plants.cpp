#include "StateEngine.h"
#include "Entity.h"
#include "RunningState.h"
#include <iostream>

int main() {
 
  // Instantiate game instance
  StateEngine* engine = new StateEngine( 
      1000, 
      800, 
      60, 
      string("Plants"));
  engine->start();

  return 0;
}
