#include "AssetManager.h"

AssetManager* AssetManager::assets = new AssetManager();


// Constructor
AssetManager::AssetManager() {
  DEFAULT_SHADER = new GLuint; 
}

// Destructor
AssetManager::~AssetManager() {
  //delete &DEFAULT_SHADER;
}

// Load assets
void AssetManager::loadAssets() {
  
  // Define default shader for all objects without a specified shader
 *DEFAULT_SHADER = LoadShaders( "shaders/TransformVertexShader.vertexshader", "shaders/ColorFragmentShader.fragmentshader" );
}

