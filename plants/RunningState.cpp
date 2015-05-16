
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
 
    Entity* earth = new Sphere(50, "images/earth.bmp"),
          * mars = new Sphere(50, "images/mars.bmp");
    mars->scale(0.5,0.5,0.5);
    mars->move(-5, 0, 0);
    //sphere->move(i + i % 11,i + i % 19,0);
    entities->push_back(earth);
    entities->push_back(mars);
    renderer->addEntity(earth);
    renderer->addEntity(mars);
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
