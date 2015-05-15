#include "ButtonComponent.h"

// Constructor
ButtonComponent::ButtonComponent(std::string text, int width, int height) : Component(width, height) {
  this->text = text;
  GLfloat* verticies = new GLfloat[3*3*2*2];
  verticies[2] = verticies[5] = verticies[8] = verticies[11] = verticies[14] = verticies[17] = 0; 
  verticies[0] = leftx;
  verticies[1] = topy;

  verticies[3] = leftx;
  verticies[4] = bottomy;

  verticies[6] = rightx;
  verticies[7] = topy;

  verticies[9] = verticies[3];
  verticies[10] = verticies[4];

  verticies[12] = verticies[6];
  verticies[13] = verticies[7];

  verticies[15] = rightx;
  verticies[16] = bottomy;

  getModel()->getVerticies()->setData(verticies, 18);
}

// Update
void ButtonComponent::update(double delta) {

}

// Mouse move event
void ButtonComponent::mouseMove(Event evt) {
  int x = evt.data[0];
  int y = evt.data[0];
}

// Mouse scroll event
void ButtonComponent::mouseScroll(Event evt) {

}

// Mouse button event
void ButtonComponent::mouseButton(Event evt) {

}

// Keyboard event
void ButtonComponent::keystroke(Event evt) {

}
