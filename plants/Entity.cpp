#include "Entity.h"

// Constructor
Entity::Entity() {
  data = new VertexData();
}

// Destructor
Entity::~Entity() {
  delete data;
}

// Get vertex data
VertexData* Entity::getData() {
  return data;
}
