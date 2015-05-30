
#include "RunningState.h"
#include "Terrain.h"
#include "Scene.h"
#include "TestEntity.h"
#include "Sphere.h"
#include "Entity.h"
#include "Renderer.h"
#include "GameState.h"
#include <iostream> 

// Constructor
RunningState::RunningState(EventManager* evtmgr, Renderer* renderer) : GameState(evtmgr, renderer) {
  cout << "Entering RunningState\n";
}

void RunningState::init(){
  
  entities = new std::vector<Entity*>();
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 5; y++){
      Terrain* terrain = new Terrain(64, 64, "images/rock.bmp");
      terrain->generate(64);
      terrain->rotate(-75);
      terrain->move(64*x, -64*y, 0);
      entities->push_back(terrain);
      renderer->addEntity(terrain);
    }
  }
  
}

// Update game
GameState* RunningState::update(double delta) {
 
  // Update current scene
  if(scene != 0)
    scene->update(delta);

  // Update camera
  renderer->getCamera()->update(delta);

  // Update entities
  for(auto e = entities->begin(); e != entities->end(); ++e){
   (*e)->update(delta);
  }

  return this;
}

// Free resources
void RunningState::dispose() {
  //scene->dispose();
}
