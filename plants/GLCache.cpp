#include "GLCache.h"
#include <common/texture.hpp>

// Constructor
GLCache::GLCache() {
}

// Destructor
GLCache::~GLCache() {
}

// Load assets
void GLCache::loadAssets() {
  
  // Define default shader for all objects without a specified shader
 DEFAULT_SHADER = LoadShaders( "shaders/StandardShading.vertexshader", "shaders/StandardShading.fragmentshader" );
}

/**
 * Returns a GL texture ID associated to the particular file system path.
 * If the texture is not already cached then it is loaded and cached in side this call. 
 */
GLuint GLCache::getTextureID(std::string texPath){
  auto it = texMap.find(texPath);
  if(it == texMap.end()){
    //load the texture
    it = texMap.insert(std::pair<std::string, GLuint>(texPath, loadBMP_custom(texPath.c_str()))).first;
  }
  return it->second;
}

/**
 * Returns the identifier of the uniform location of a varialbe inside the shader, given a program ID
 * If the program ID does not exist in the outer map (which maps program IDs to a map of uniform location to identifiers), it creates it
 * If the uniform variable does not exist is is created similarly, but with the true uniform location call 
 */
GLuint GLCache::getUniformLocation(GLuint pID, std::string var){
  auto progMap = uniformMap.find(pID);
  if(progMap == uniformMap.end())
    progMap = uniformMap.insert(
        std::pair<GLuint, std::map<std::string, GLuint>>(pID, std::map<std::string, GLuint>())).first;
  auto varIt = progMap->second.find(var);
  if(varIt == progMap->second.end())
    varIt = progMap->second.insert(std::pair<std::string, GLuint>(var, glGetUniformLocation(pID, var.c_str()))).first;
  return varIt->second;
}
