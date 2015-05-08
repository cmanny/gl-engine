#include <vector>

#include "RunningState.h"
#include "Scene.h"
#include "TestEntity.h"
#include "Entity.h"
#include "Renderer.h"

// Constructor
RunningState::RunningState() {
  
  // TEST --------------------
  TestEntity* entity = new TestEntity();
  std::vector<Entity*>* entities = new std::vector<Entity*>();
  entities->push_back(entity);
  Renderer::getInstance()->setEntities(entities);
  // -------------------------
}

// Update game
void RunningState::update(double delta) {
 
  // Update current scene
  if(scene != 0)
    scene->update(delta);
}

// Free resources
void RunningState::dispose() {
  scene->dispose();
}
