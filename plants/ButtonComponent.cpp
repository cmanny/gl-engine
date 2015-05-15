#include "ButtonComponent.h"

// Constructor
ButtonComponent::ButtonComponent(std::string text, int width, int height) : Component(width, height) {
  this->text = text;
  vector<glm::vec3>* verticies = new vector<glm::vec3>();
  
  verticies->push_back(glm::vec3(leftx, topy, 0.0f)); 
  verticies->push_back(glm::vec3(leftx, bottomy, 0.0f)); 
  verticies->push_back(glm::vec3(rightx, topy, 0.0f)); 
  verticies->push_back(glm::vec3(leftx, bottomy, 0.0f)); 
  verticies->push_back(glm::vec3(rightx, topy, 0.0f)); 
  verticies->push_back(glm::vec3(rightx, bottomy, 0.0f)); 

  getModel()->getVerticies()->setData(verticies);
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
