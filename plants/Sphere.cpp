#include "Sphere.h"

Sphere::Sphere(int detail){
  this->detail = detail;
  
}

void Sphere::update(double delta){
  rotate(2.0f);
}
