#include "LoadingState.h"
#include "AssetManager.h"
#include "Renderer.h"
#include "GameState.h"

// Constructor
LoadingState::LoadingState(EventManager* evtmgr, Renderer* renderer) :
  GameState(evtmgr, renderer)
{

}

// Initialise state
void LoadingState::init() {

}

// Update 
GameState* LoadingState::update(double delta) {
  AssetManager::assets->loadAssets();

  return this;
}

// Free resources
void LoadingState::dispose() {

}
