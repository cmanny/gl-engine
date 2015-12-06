#ifndef COMPONENT_H
#define COMPONENT_H

#include "Entity.h"
#include "Event.h"

class Component : public Entity {
  protected:
    int width, height;
    GLfloat leftx, rightx, topy, bottomy;

  public:
    Component(int width, int height);

    virtual void mouseMove(Event evt) = 0;
    virtual void mouseScroll(Event evt) = 0;
    virtual void mouseButton(Event evt) = 0;
    virtual void keystroke(Event evt) = 0;  

    void setWidth(int width);
    void setHeight(int height);
    
    int getWidth();
    int getHeight();

    bool contains(Component* component);
    bool contains(int x, int y);
    bool contains(int x, int y, int width, int height);
};

#endif /* Component.h */
