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

  evtmgr->enableCallback(new Callback<ComponentManager>(this, EVT_MOUSEMOVE, &ComponentManager::mouseMove));
  evtmgr->enableCallback(new Callback<ComponentManager>(this, EVT_MOUSESCROLL, &ComponentManager::mouseScroll));
  evtmgr->enableCallback(new Callback<ComponentManager>(this, EVT_MOUSEBUTTON, &ComponentManager::mouseButton));
  evtmgr->enableCallback(new Callback<ComponentManager>(this, EVT_KEY, &ComponentManager::keystroke));
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

