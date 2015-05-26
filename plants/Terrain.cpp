#include "Terrain.h"

Terrain::Terrain(GLfloat w, GLfloat h, std::string texture) : distribution(0.5, 0.25){
  this->w = w;
  this->h = h;
  getModel()->loadTexture(texture);
}

void Terrain::generate(int N){
  std::vector<glm::vec3>* vertices = new std::vector<glm::vec3>();
  std::vector<glm::vec2>* uvs = new std::vector<glm::vec2>();
  std::vector<glm::vec3>* normals = new std::vector<glm::vec3>();
  
  GLfloat dx = w/(GLfloat)N, dy = h/(GLfloat)N; //deltas to be applied to the integers in the meshgrid

  Complex* hmap = new Complex[N*N];
  int signs[] = {1,-1};
  glm::vec3* normalMesh = new glm::vec3[N*N];
  
  for(int i = 0; i < N*N; i++) hmap[i] = Complex( (i/(double)(N*N))*((double) rand() / RAND_MAX) , 0.0); 
  FFT fft(N);
  for(int i = 0; i < N; i++) fft.transform(hmap, hmap, 1, i*N, false); //rows
  for(int i = 0; i < N; i++) fft.transform(hmap, hmap, N, i, false); //columns 
  //Apply filter in the frequency domain
  for(int y = 0; y < N; y++){
    for(int x = 0; x < N; x++){
      int i = y * N + x;
      double f = sqrt((x-N/2)/float(N) * (x-N/2)/float(N) + (y-N/2)/float(N) * (y-N/2)/float(N));
      f = f < 1.0f/N ? 1.0f / N : f;
      hmap[i] *= 1.0f/pow(f, 2);
    }
  }
  for(int i = 0; i < N; i++) fft.transform(hmap, hmap, 1, i*N, true); //rows
  for(int i = 0; i < N; i++) fft.transform(hmap, hmap, N, i, true); //columns 
  for(int y = 0; y < N; y++) for(int x = 0; x < N; x++) hmap[y*N + x] /= Complex(signs[(y+x)%2]*10,0.0);

  for(int y = 0; y < N-1; y++){
    for(int x = 0; x < N-1; x++){
      int i = y*N + x;
      GLfloat xc = x*dx;
      GLfloat yc = y*dy;
      vertices->push_back(glm::vec3(xc,yc,hmap[i].real()));
      vertices->push_back(glm::vec3(xc+dx, yc, hmap[i+1].real()));
      vertices->push_back(glm::vec3(xc+dx, yc+dy, hmap[i + N + 1].real()));
     
      glm::vec3 midEdge = glm::vec3(xc+dx, yc+dy, hmap[i + N + 1].real()) - glm::vec3(xc,yc,hmap[i].real());
      glm::vec3 horEdge = glm::vec3(xc+dx, yc, hmap[i+1].real()) - glm::vec3(xc,yc,hmap[i].real());
      glm::vec3 t1Norm = glm::normalize(glm::cross( horEdge, midEdge));
      t1Norm = glm::normalize(glm::vec3(t1Norm.x, t1Norm.y, 1));
      //for(int i = 0; i < 3; i++) normals->push_back(t1Norm);
      uvs->push_back(glm::vec2(0,0));
      uvs->push_back(glm::vec2((xc+dx)/N,(yc)/N));
      uvs->push_back(glm::vec2((xc+dx)/N,(yc+dy)/N));

      vertices->push_back(glm::vec3(xc, yc, hmap[i].real()));
      vertices->push_back(glm::vec3(xc+dx, yc+dy, hmap[i + N + 1].real()));
      vertices->push_back(glm::vec3(xc, yc + dy, hmap[i + N].real()));

      glm::vec3 vertEdge = glm::vec3(xc, yc + dy, hmap[i + N].real()) - glm::vec3(xc, yc, hmap[i].real());

      glm::vec3 t2Norm = glm::cross(vertEdge, midEdge);
      t2Norm = glm::normalize(glm::vec3(t2Norm.x, t2Norm.y, 1));
      //for(int i = 0; i < 3; i++) normals->push_back(t2Norm);
       
      uvs->push_back(glm::vec2(0,0));
      uvs->push_back(glm::vec2((xc+dx)/N,(yc+dy)/N));
      uvs->push_back(glm::vec2((xc)/N,(yc+dy)/N));
      normalMesh[i] += t1Norm + t2Norm;
      normalMesh[i+1] += t1Norm;
      normalMesh[i+ N + 1] += t1Norm + t2Norm;
      normalMesh[i+N] += t2Norm;
    }
  }

  for(int y = 0; y < N; y++){
    for(int x = 0; x < N; x++){
      int i = y*N + x;
      normalMesh[i] = glm::vec3(normalMesh[i].x, normalMesh[i].y, 2);
      normalMesh[i] = glm::normalize(normalMesh[i]);
    }
  }
  for(int y = 0; y < N-1; y++){
    for(int x = 0; x < N-1; x++){
      int i = y*N + x;
      normals->push_back(normalMesh[i]);
      normals->push_back(normalMesh[i+1]);
      normals->push_back(normalMesh[i+N+1]);

      normals->push_back(normalMesh[i]);
      normals->push_back(normalMesh[i+N+1]); 
      normals->push_back(normalMesh[i+N]);
    }
  }
  getModel()->getVertices()->setData(vertices);
  getModel()->getNormals()->setData(normals);
  getModel()->getUVs()->setData(uvs);
  getModel()->buildVBOIndex(); 
//  std::cout << std::max_element(getModel()->getIndices()->getData()->size()) << " " << pow(2, sizeof(unsigned short)*8);
}


void Terrain::printMesh(Complex* hmap, int N){
  for(int y = 0; y < N; y++){
    for(int x = 0; x < N; x++){
        std::cout << hmap[x + y*N] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
