#include "Sphere.h"

Sphere::Sphere(GLfloat detail){
  this->detail = detail;
  int size = detail*detail*18;
  GLfloat* verticies = new GLfloat[size];
  GLfloat zc = 0, yc = 0, xc= 0, angInc = 2*M_PI/detail;
  GLfloat decrement = 1.0f/detail;
  int count = 0;
  for(GLfloat angZ = 0.0f; angZ < M_PI; angZ += angInc){
    zc = glm::cos(angZ);
    GLfloat nextZc = glm::cos(angZ + angInc);
    GLfloat nextR = glm::sqrt(1 - nextZc*nextZc);
    GLfloat r = glm::sqrt(1- zc*zc);
    for(GLfloat ang = 0.0f; ang < 2*M_PI; ang += angInc){
      GLfloat yc = r*glm::sin(ang);
      GLfloat xc = r*glm::cos(ang);
      GLfloat leftYc = nextR*glm::sin(ang);
      GLfloat leftXc = nextR*glm::cos(ang);
      GLfloat rightYc = nextR*glm::sin(ang + angInc);
      GLfloat rightXc = nextR*glm::cos(ang + angInc);
      GLfloat nextYc = r*glm::sin(ang + angInc);
      GLfloat nextXc = r*glm::cos(ang + angInc);

      verticies[count+0] = xc;
      verticies[count+1] = yc;
      verticies[count+2] = zc;

      verticies[count+3] = leftXc;
      verticies[count+4] = leftYc;
      verticies[count+5] = nextZc;

      verticies[count+6] = rightXc;
      verticies[count+7] = rightYc;
      verticies[count+8] = nextZc;

      verticies[count+9] = xc;
      verticies[count+10] = yc;
      verticies[count+11] = zc;

      verticies[count+15] = rightXc;
      verticies[count+16] = rightYc;
      verticies[count+17] = nextZc;

      verticies[count+12] = nextXc;
      verticies[count+13] = nextYc;
      verticies[count+14] = zc;
      count += 18;
    } 
  }
  GLfloat* colourData = new GLfloat[count];
  for(int i = 0; i < count; i += 3){
    colourData[i] = glm::cos(i*M_PI/180);
    colourData[i+1] = glm::sin(i*M_PI/180);
    colourData[i+2] = glm::cos(i*i*M_PI/180);
  }
  std::cout << "Count: " << count << "\n";
  getData()->setVertexData(verticies, count);
  getColour()->setVertexData(colourData, count);
  angle = 0;
}

void Sphere::update(double delta){
  rotate(0.1);
  //move(0.1*glm::cos(angle),0.1*glm::sin(angle),0.1*glm::cos(angle));
  angle += M_PI*2/256;
}
