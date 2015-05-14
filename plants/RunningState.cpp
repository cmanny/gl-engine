
#include "RunningState.h"
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
 
  for(int i = 50; i < 51; i++){ 
    Entity* sphere = new Sphere(i);
    //sphere->move(i + i % 11,i + i % 19,0);
    entities->push_back(sphere);
    renderer->addEntity(sphere);
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
