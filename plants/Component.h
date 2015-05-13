#ifndef COMPONENT_H
#define COMPONENT_H

#include "Entity.h"
#include "Event.h"

class Component : public Entity {
  public:
    Component();

    virtual void mouseMove(Event evt) = 0;
    virtual void mouseScroll(Event evt) = 0;
    virtual void mouseButton(Event evt) = 0;
    virtual void keystroke(Event evt) = 0;  
};

#endif /* Component.h */
