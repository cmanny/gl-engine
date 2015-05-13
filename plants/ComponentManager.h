#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "Component.h"
#include "EventManager.h"
#include <vector>

class ComponentManager {
  private:
    EventManager* evtmgr;
    bool enabledCallbacks;
    vector<Component*>* components;

  public:
    ComponentManager(EventManager* evtmgr);
    ~ComponentManager();
    
    void update(double delta);

    void enable();
    void disable();
    void add(Component* component);

    void mouseMove(Event evt);
    void mouseScroll(Event evt);
    void mouseButton(Event evt);
    void keystroke(Event evt);
};

#endif
