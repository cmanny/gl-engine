#include "MenuState.h"
#include "RunningState.h"
#include <iostream>
#include "ButtonComponent.h"
#include <string>

// Constructor
MenuState::MenuState(EventManager* evtmgr, Renderer* renderer) : 
  GameState(evtmgr, renderer)
{
  cout << "Entering MenuState\n";
}

// Initialise menu state
void MenuState::init() {
  manager = new ComponentManager(evtmgr);

  // Add temp button
  //Component* btnTest = new ButtonComponent("Jimmers", 5, 10);

  //renderer->addEntity(btnTest);
  //manager->add(btnTest);
}

// Update
GameState* MenuState::update(double delta){

  manager->update(delta);

  // Navigate to running state
  GameState* g = new RunningState(evtmgr, renderer);
  g->init();
  return g;

 return this; 
}

// Free resources
void MenuState::dispose(){

}
