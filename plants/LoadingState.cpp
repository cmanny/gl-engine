#include "LoadingState.h"
#include "MenuState.h"
#include <iostream>

// Constructor
LoadingState::LoadingState(EventManager* evtmgr, Renderer* renderer) :
  GameState(evtmgr, renderer)
{
  cout << "Entering LoadingState\n";
}

// Initialise state
void LoadingState::init() {
}

// Update 
GameState* LoadingState::update(double delta) {

  GameState* g = new MenuState(evtmgr, renderer);
  g->init();

  return g;
}

// Free resources
void LoadingState::dispose() {

}
