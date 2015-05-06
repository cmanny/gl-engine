#include "Renderer.h"

Renderer::Renderer(int scrW, int scrH){
  this->screenW = scrW;
  this->screenH = scrH;
}

void Renderer::setEntities(vector<Entity*>* entities){
  this->entities = entities;
}

void draw(){
  //Todo
}
