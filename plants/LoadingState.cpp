#include "LoadingState.h"
#include "AssetManager.h"
#include "Renderer.h"
#include "GameState.h"
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
  AssetManager::assets->loadAssets();

  return new MenuState(evtmgr, renderer);
}

// Free resources
void LoadingState::dispose() {

}
