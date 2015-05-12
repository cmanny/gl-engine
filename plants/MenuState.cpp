#include "MenuState.h"
#include "RunningState.h"
#include <iostream>

// Constructor
MenuState::MenuState(EventManager* evtmgr, Renderer* renderer) : 
  GameState(evtmgr, renderer)
{
  cout << "Entering MenuState\n";
}

// Initialise menu state
void MenuState::init() {

}

// Update
GameState* MenuState::update(double delta){
  return new RunningState(evtmgr, renderer);
}

// Free resources
void MenuState::dispose(){

}
