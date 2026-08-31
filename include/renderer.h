#ifndef RENDERER_H
#define RENDERER_H

#include <GLFW/glfw3.h>
#include "objLoader.h"
#include "lightManager.h"

class Renderer {
public:
    void init(GLFWwindow* window);
    void render(const Model& model, const LightManager& lightManager);
};

#endif