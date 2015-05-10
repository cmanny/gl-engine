#ifndef ENTITY_H
#define ENTITY_H
#include "VertexData.h"

class Entity {
  private:
    VertexData* data;
    double x, y;

  public:
    Entity();
    ~Entity();
    virtual void update(double delta) = 0;
    VertexData* getData();

    void setX(double x);
    void setY(double y);
    void incX(double i);
    void incY(double i);
    double getX();
    double getY();
};

#endif
