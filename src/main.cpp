#include <iostream>
#include "objLoader.h"
#include "lightManager.h"
#include "renderer.h"
#include "optimization.h"

int main() {
    // Inicializar GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Crear ventana
    GLFWwindow* window = glfwCreateWindow(800, 600, "Motor de Renderizado", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Cargar modelo OBJ
    Model model = loadModel("resources/model.obj");

    // Configurar luces
    LightManager lightManager;
    lightManager.addLight(Light(glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(1.0f, 1.0f, 1.0f)));

    // Inicializar renderizador
    Renderer renderer;
    renderer.init(window);

    // Bucle de renderizado
    while (!glfwWindowShouldClose(window)) {
        // Procesar entrada
        glfwPollEvents();

        // Renderizar escena
        renderer.render(model, lightManager);

        // Intercambio de buffers
        glfwSwapBuffers(window);
    }

    // Limpiar recursos
    glfwTerminate();
    return 0;
}