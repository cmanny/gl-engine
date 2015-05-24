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
  Complex* meshgrid = new Complex[N*N];
  for(int i = 0; i < N*N; i++) meshgrid[i] = Complex(distribution(rEngine), distribution(rEngine));
  
  printMesh(meshgrid, N);
  FFT fft(N);
  for(int i = 0; i < N; i++) fft.transform(meshgrid, meshgrid, 1, i*N, false); //rows
  for(int i = 0; i < N; i++) fft.transform(meshgrid, meshgrid, N, i, false); //columns 
  printMesh(meshgrid, N);

  for(int y = 0; y < N; y++){
    for(int x = 0; x < N; x++){
      int i = y * N + x;
      double f = sqrt((x-N/2)/float(N) * (x-N/2)/float(N) + (y-N/2)/float(N) * (y-N/2)/float(N));
      f = f < 1.0f/N ? 1.0f / N : f;
      meshgrid[i] *= 1.0f/pow(f, 1);
    }
  }
  
  printMesh(meshgrid, N);
  for(int i = 0; i < N; i++) fft.transform(meshgrid, meshgrid, 1, i*N, true); //rows
  for(int i = 0; i < N; i++) fft.transform(meshgrid, meshgrid, N, i, true); //columns 

  printMesh(meshgrid, N);
}


void Terrain::printMesh(Complex* meshgrid, int N){
  for(int y = 0; y < N; y++){
    for(int x = 0; x < N; x++){
        std::cout << meshgrid[x + y*N] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
