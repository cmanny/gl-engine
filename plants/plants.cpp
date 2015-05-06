#include "StateEngine.h"

int main() {
  
  // Instantiate game instance
  StateEngine* engine =new StateEngine((GameState*)NULL, 640, 480, 60, string("Plants"));
  engine->start();

  return 0;
}
