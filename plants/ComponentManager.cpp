#include "ComponentManager.h"

// Constructor
ComponentManager::ComponentManager(EventManager* evtmgr) {
  this->evtmgr = evtmgr;
  components = new vector<Component*>();
}

// Destructor
ComponentManager::~ComponentManager() {
  delete components;
}

// Initialise callbacks
void ComponentManager::enable() {
  if(enabledCallbacks)
    return;
  enabledCallbacks = true;

  evtmgr->enableCallback(memberCallback(&ComponentManager::mouseMove, this, EVT_MOUSEMOVE));
  evtmgr->enableCallback(memberCallback(&ComponentManager::mouseScroll, this, EVT_MOUSESCROLL));
  evtmgr->enableCallback(memberCallback(&ComponentManager::mouseButton, this, EVT_MOUSEBUTTON));
  evtmgr->enableCallback(memberCallback(&ComponentManager::keystroke, this, EVT_KEY));
}

// Disable callbacks
void ComponentManager::disable() {
  if(!enabledCallbacks)
    return;

  /*evtmgr->disableCallback(&ComponentManager::mouseMove);
  evtmgr->disableCallback(&ComponentManager::mouseScroll);
  evtmgr->disableCallback(&ComponentManager::mouseButton);
  evtmgr->disableCallback(&ComponentManager::keystroke)*/;
}

// Update components
void ComponentManager::update(double delta) {
  for(int i = 0; i<components->size(); i++)
    components->at(i)->update(delta);
}

// Add component
void ComponentManager::add(Component* component) {
  components->push_back(component);
}

// Handle mouse move events
void ComponentManager::mouseMove(Event evt) {
  for(int i = 0; i<components->size(); i++) {
    components->at(i)->mouseMove(evt);
  }
}

// Handle mouse scroll events
void ComponentManager::mouseScroll(Event evt) {
 for(int i = 0; i<components->size(); i++) {
    components->at(i)->mouseScroll(evt);
  }
}

// Handle mouse click events
void ComponentManager::mouseButton(Event evt) {
 for(int i = 0; i<components->size(); i++) {
    components->at(i)->mouseButton(evt);
  }
}

// Handle keystrokes
void ComponentManager::keystroke(Event evt) {
 for(int i = 0; i<components->size(); i++) {
    components->at(i)->keystroke(evt);
  }
}

