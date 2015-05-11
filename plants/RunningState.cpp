
#include "RunningState.h"
#include "Scene.h"
#include "TestEntity.h"
#include "Entity.h"
#include "Renderer.h"

// Constructor
RunningState::RunningState(EventManager* evtmgr, Renderer* renderer) {
  this->evtmgr = evtmgr;
  this->renderer = renderer;
}

void RunningState::init(){
  TestEntity* entity = new TestEntity();
  entities = new std::vector<Entity*>();
  entities->push_back(entity);
  renderer->setEntities(entities);
}

// Update game
void RunningState::update(double delta) {
 
  // Update current scene
  if(scene != 0)
    scene->update(delta);

  // Update camera
  renderer->getCamera()->update(delta);
  for(auto e = entities->begin(); e != entities->end(); ++e){
    (*e)->update(delta);
  }
}

// Free resources
void RunningState::dispose() {
  scene->dispose();
}
