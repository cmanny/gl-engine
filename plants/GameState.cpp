#include "GameState.h"

// Constructor
GameState::GameState(EventManager* evtmgr, Renderer* renderer) {
  this->evtmgr = evtmgr;
  this->renderer = renderer;
}
