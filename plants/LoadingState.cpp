#include "LoadingState.h"
#include "AssetManager.h"

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
