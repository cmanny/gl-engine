#include "Sphere.h"

Sphere::Sphere(GLfloat detail){
  this->detail = detail;

  float width = 2048.0f, height = 1024.0f;
  float xInc = 1.0f / detail, yInc = 1.0f / detail;
  float uvX = 0.0f, uvY = 0.0f;
  vector<glm::vec3> verticies = new vector<glm::vec3>();
  vector<glm::vec3> uvs = new vector<glm::vec3>();
  GLfloat zc = 0, yc = 0, xc= 0, angInc = 2*M_PI/detail;
  GLfloat decrement = 1.0f/detail;
  for(GLfloat angZ = 0.0f; angZ < M_PI; angZ += angInc){
    zc = glm::cos(angZ);
    GLfloat nextZc = glm::cos(angZ + angInc);
    GLfloat nextR = glm::sqrt(1 - nextZc*nextZc);
    GLfloat r = glm::sqrt(1- zc*zc);
    uvX = 0.0f;
    for(GLfloat ang = 0.0f; ang < 2*M_PI; ang += angInc){
      GLfloat yc = r*glm::sin(ang);
      GLfloat xc = r*glm::cos(ang);
      GLfloat leftYc = nextR*glm::sin(ang);
      GLfloat leftXc = nextR*glm::cos(ang);
      GLfloat rightYc = nextR*glm::sin(ang + angInc);
      GLfloat rightXc = nextR*glm::cos(ang + angInc);
      GLfloat nextYc = r*glm::sin(ang + angInc);
      GLfloat nextXc = r*glm::cos(ang + angInc);
      //1st verticies
      verticies->push_back(glm::vec3(xc, yc, zc));
      verticies->push_back(glm::vec3(leftXc, leftYc, nextZc));
      verticies->push_back(glm::vec3(rightXc, rightYc, nextZc));
      //1st uvs
      uvs->push_back(glm::vec3(uvX, uvY));
      uvs->push_back(glm::vec3(uvX, uvY + yInc));
      uvs->push_back(glm::vec3(uvX + xInc, uvY + yInc)); 
      //2nd verticies
      verticies->push_back(glm::vec3(xc, yc, zc));
      verticies->push_back(glm::vec3(rightXc, rightYc, nextZc));
      verticies->push_back(glm::vec3(nextXc, nextYc, zc));
      //2nd uvs
      uvs->push_back(glm::vec3(uvX, uvY));
      uvs->push_back(glm::vec3(uvX + xInc, uvY + yInc));
      uvs->push_back(glm::vec3(uvX + xInc, uvY)); 
      uvX += incX; 
    }
    uvY += incY; 
  }
  getModel()->getVerticies()->setData(verticies);
  getModel()->getUVs()->setData(uvs);
  getModel()->loadTexture("images/earth.bmp");
  //getModel()->buildVBOIndex();
  angle = 0;
}

void Sphere::update(double delta){
  rotate(0.1);
  //move(0.1*glm::cos(angle),0.1*glm::sin(angle),0.1*glm::cos(angle));
  angle += M_PI*2/256;
}
