#include "Sphere.h"
#include <glm/gtx/compatibility.hpp>

glm::vec2 makeUV(GLfloat x, GLfloat y, GLfloat z){
  return glm::vec2( 0.5 + glm::atan2(y,x)/(M_PI*2), 0.5 - glm::asin(z)/M_PI);
}

Sphere::Sphere(GLfloat detail, std::string filepath){
  this->detail = detail;

  GLfloat width = 2048.0f, height = 1024.0f;
  std::vector<glm::vec3>* vertices = new std::vector<glm::vec3>();
  std::vector<glm::vec2>* uvs = new std::vector<glm::vec2>();
  std::vector<glm::vec3>* normals = new std::vector<glm::vec3>();
  GLfloat zc = 0, yc = 0, xc= 0, angInc = 2*M_PI/detail;
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

      //Make sure the bridge between +PI and -PI is handled
      if(nextYc <= 0 && yc > 0){
        nextYc = 0+(1.0/(1<<(sizeof(GLfloat)*8-2)));
        rightYc = nextYc;
      }
      //1st vertices
      vertices->push_back(glm::vec3(xc, yc, zc));
      vertices->push_back(glm::vec3(leftXc, leftYc, nextZc));
      vertices->push_back(glm::vec3(rightXc, rightYc, nextZc));
      //1st uvs
      uvs->push_back(makeUV(xc, yc, zc));
      uvs->push_back(makeUV(leftXc, leftYc, nextZc));
      uvs->push_back(makeUV(rightXc, rightYc, nextZc));
      //1st normals
      normals->push_back(glm::normalize(glm::vec3(xc, yc, zc)));
      normals->push_back(glm::normalize(glm::vec3(leftXc, leftYc, nextZc)));
      normals->push_back(glm::normalize(glm::vec3(rightXc, rightYc, nextZc)));

      //2nd vertices
      vertices->push_back(glm::vec3(xc, yc, zc));
      vertices->push_back(glm::vec3(rightXc, rightYc, nextZc));
      vertices->push_back(glm::vec3(nextXc, nextYc, zc));
      //2nd uvs
      uvs->push_back(makeUV(xc, yc, zc));
      uvs->push_back(makeUV(rightXc, rightYc, nextZc));
      uvs->push_back(makeUV(nextXc, nextYc, zc));
      
      normals->push_back(glm::normalize(glm::vec3(xc, yc, zc)));
      normals->push_back(glm::normalize(glm::vec3(rightXc, rightYc, nextZc)));
      normals->push_back(glm::normalize(glm::vec3(nextXc, nextYc, zc)));
    }
  }
  getModel()->getVertices()->setData(vertices);
  getModel()->getUVs()->setData(uvs);
  getModel()->getNormals()->setData(normals);
  getModel()->loadTexture(filepath);
  getModel()->buildVBOIndex();
  angle = 0;
}

void Sphere::update(double delta){
  rotate(0.1);
  //move(0.1*glm::cos(angle),0.1*glm::sin(angle),0.1*glm::cos(angle));
  angle += M_PI*2/256;
}
