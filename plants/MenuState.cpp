#include "MenuState.h"

// Constructor
MenuState::MenuState(EventManager* evtmgr, Renderer* renderer) : 
  GameState(evtmgr, renderer)
{

}

// Initialise menu state
void MenuState::init() {

}

// Update
GameState* MenuState::update(double delta){
  return this;
}

// Free resources
void MenuState::dispose(){

}
