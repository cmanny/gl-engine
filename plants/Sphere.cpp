#include "Sphere.h"

Sphere::Sphere(GLfloat detail){
  this->detail = detail;

  GLfloat width = 2048.0f, height = 1024.0f;
  GLfloat incX = 1.0f / detail, incY = 1.0f / detail;
  GLfloat uvX = 0.0f, uvY = 0.0f;
  std::vector<glm::vec3>* vertices = new std::vector<glm::vec3>();
  std::vector<glm::vec2>* uvs = new std::vector<glm::vec2>();
  std::vector<glm::vec3>* normals = new std::vector<glm::vec3>();
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
      //1st vertices
      vertices->push_back(glm::vec3(xc, yc, zc));
      vertices->push_back(glm::vec3(leftXc, leftYc, nextZc));
      vertices->push_back(glm::vec3(rightXc, rightYc, nextZc));
      //1st uvs
      uvs->push_back(glm::vec2(uvX, uvY));
      uvs->push_back(glm::vec2(uvX, uvY + incY));
      uvs->push_back(glm::vec2(uvX + incX, uvY + incY)); 
      //1st normals
      normals->push_back(glm::normalize(glm::vec3(xc, yc, zc)));
      normals->push_back(glm::normalize(glm::vec3(leftXc, leftYc, nextZc)));
      normals->push_back(glm::normalize(glm::vec3(rightXc, rightYc, nextZc)));

      //2nd vertices
      vertices->push_back(glm::vec3(xc, yc, zc));
      vertices->push_back(glm::vec3(rightXc, rightYc, nextZc));
      vertices->push_back(glm::vec3(nextXc, nextYc, zc));
      //2nd uvs
      uvs->push_back(glm::vec2(uvX, uvY));
      uvs->push_back(glm::vec2(uvX + incX, uvY + incY));
      uvs->push_back(glm::vec2(uvX + incX, uvY)); 
      
      normals->push_back(glm::normalize(glm::vec3(xc, yc, zc)));
      normals->push_back(glm::normalize(glm::vec3(rightXc, rightYc, nextZc)));
      normals->push_back(glm::normalize(glm::vec3(nextXc, nextYc, zc)));


//      std::cout << uvX << " " << uvY << " " << "\n";

      uvX += incX; 
    }
    uvY += incY; 
  }

std::cout << "\n" << vertices->size() << " " <<
               uvs->size() << " " <<
               normals->size() << " ";

  getModel()->getVertices()->setData(vertices);
  getModel()->getUVs()->setData(uvs);
  getModel()->getNormals()->setData(normals);
  getModel()->loadTexture("images/earth.bmp");
  getModel()->buildVBOIndex();

    angle = 0;
}

void Sphere::update(double delta){
  rotate(1);
  //move(0.1*glm::cos(angle),0.1*glm::sin(angle),0.1*glm::cos(angle));
  angle += M_PI*2/256;
}
