#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <common/shader.hpp>

class AssetManager {
  public:
    static AssetManager* assets;
    AssetManager();
    ~AssetManager();
    void loadAssets();

    // Define shaders
    GLuint DEFAULT_SHADER = 0;
};

#endif
