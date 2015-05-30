#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <common/shader.hpp>
#include <map>
#include <string>

class AssetManager {
  private:
    std::map<std::string, GLuint> texMap;
  public:
    static AssetManager* assets;
    AssetManager();
    ~AssetManager();
    void loadAssets();
    GLuint getTextureID(std::string);

    // Define shaders
    GLuint DEFAULT_SHADER = 0;
};

#endif
