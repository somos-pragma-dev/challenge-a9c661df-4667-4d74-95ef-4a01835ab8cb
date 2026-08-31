#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include <vector>
#include <glm/glm.hpp>

struct Light {
    glm::vec3 position;
    glm::vec3 color;
};

class LightManager {
public:
    void addLight(const Light& light);
private:
    std::vector<Light> lights;
};

#endif