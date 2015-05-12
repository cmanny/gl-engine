#include "LoadingState.h"
#include "AssetManager.h"
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

  AssetManager::assets->loadAssets();
}

// Update 
GameState* LoadingState::update(double delta) {

  return new MenuState(evtmgr, renderer);
}

// Free resources
void LoadingState::dispose() {

}
