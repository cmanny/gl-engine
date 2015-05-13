#ifndef BUTTON_COMPONENT_H
#define BUTTON_COMPONENT_H

#include "Component.h"
#include "Event.h"
#include <string>

class ButtonComponent : public Component {
  private:
    std::string text;
 
  public:
    ButtonComponent(std::string text, int width, int height);
    void update(double delta);
    void mouseMove(Event evt);
    void mouseScroll(Event evt);
    void mouseButton(Event evt);
    void keystroke(Event evt);
};

#endif
