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
  GameState* g = new RunningState(evtmgr, renderer);
  g->init();
  return g; 
}

// Free resources
void MenuState::dispose(){

}
