#include "AssetManager.h"
#include <common/texture.hpp>

AssetManager* AssetManager::assets = new AssetManager();


// Constructor
AssetManager::AssetManager() {
}

// Destructor
AssetManager::~AssetManager() {
  //delete &DEFAULT_SHADER;
}

// Load assets
void AssetManager::loadAssets() {
  
  // Define default shader for all objects without a specified shader
 DEFAULT_SHADER = LoadShaders( "shaders/StandardShading.vertexshader", "shaders/StandardShading.fragmentshader" );
}

GLuint AssetManager::getTextureID(std::string texPath){
  auto it = texMap.find(texPath);
  if(it == texMap.end()){
    //load the texture
    it = texMap.insert(std::pair<std::string, GLuint>(texPath, loadBMP_custom(texPath.c_str()))).first;
  }
  return it->second;
}

GLuint AssetManager::getUniformLocation(GLuint pID, std::string var){
  auto progMap = uniformMap.find(pID);
  if(progMap == uniformMap.end())
    progMap = uniformMap.insert(
        std::pair<GLuint, std::map<std::string, GLuint>>(pID, std::map<std::string, GLuint>())).first;
  auto varIt = progMap->second.find(var);
  if(varIt == progMap->second.end())
    varIt = progMap->second.insert(std::pair<std::string, GLuint>(var, glGetUniformLocation(pID, var.c_str()))).first;
  return varIt->second;
}
