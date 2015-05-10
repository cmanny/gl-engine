#ifndef ENTITY_H
#define ENTITY_H
#include "VertexData.h"

class Entity {
  private:
    VertexData* data;
  public:
    Entity();
    ~Entity();
    virtual void update(double delta()) {};
    VertexData* getData();
};

#endif
