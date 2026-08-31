#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <string>
#include <vector>

struct Vertex {
    float x, y, z;
};

struct Model {
    std::vector<Vertex> vertices;
};

Model loadModel(const std::string& path);

#endif