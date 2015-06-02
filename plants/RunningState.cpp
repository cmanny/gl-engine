
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
  this->update(1);  
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 5; y++){
      Terrain* terrain = new Terrain(64, 64, "images/rock.bmp");
      terrain->generate(32, 5.0/sqrt(((2.5-x)*(2.5-x)+(2.5-y)*(2.5-y)))/8.0);
      terrain->rotate(-45);
      terrain->move((64)*x, -63*y-1, 0);
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
