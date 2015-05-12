
#include "RunningState.h"
#include "Scene.h"
#include "TestEntity.h"
#include "Sphere.h"
#include "Entity.h"
#include "Renderer.h"
#include "GameState.h"

// Constructor
RunningState::RunningState(EventManager* evtmgr, Renderer* renderer) : GameState(evtmgr, renderer) {
  
}

void RunningState::init(){
  entities = new std::vector<Entity*>();
 
  for(int i = 20; i < 100; i++){ 
    Entity* sphere = new Sphere(i);
    sphere->move(i + i % 11,i + i % 19,0);
    entities->push_back(sphere);
  }
  renderer->setEntities(entities);
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
  scene->dispose();
}
