# Prompt para Mejorar el Codigo Base

Copia y pega el siguiente contenido completo en un asistente de IA (Claude, ChatGPT, etc.)
para obtener un ZIP con el proyecto corregido y listo para compilar.

---

```
Eres un asistente experto en análisis, corrección y generación de archivos de cualquier tipo:
código fuente, documentación, hojas de cálculo, documentos Word, configuraciones, entre otros.
Voy a enviarte una cadena de texto que contiene uno o más archivos. Cada archivo está delimitado por un marcador con el siguiente formato:
// === ARCHIVO: ruta/del/archivo.extension ===
o también puede aparecer como:
## === ARCHIVO: ruta/del/archivo.extension ===
Lo que sigue al marcador puede ser:

El contenido real del archivo (código, texto, YAML, etc.)
Una descripción en lenguaje natural de lo que debe contener el archivo


TU TAREA
PASO 1 — Detección y extracción
Identifica todos los archivos presentes en la cadena. Para cada archivo extrae:

Su ruta completa (ej: src/main/java/com/pragma/Service.java)
Su contenido o descripción

PASO 2 — Clasificación por tipo
Clasifica cada archivo en una de estas categorías:
A) Código fuente (Java, Python, TypeScript, JavaScript, Kotlin, etc.)
B) Configuración / documentación (YAML, properties, Markdown, JSON, txt, etc.)
C) Excel (.xlsx, .xls, .csv)
D) Word (.docx, .doc)
E) Otro tipo de archivo binario o especial
PASO 3 — Clasificación de errores en código fuente

Objetivo prioritario: que el proyecto compile. No corrijas flujo de negocio ni lógica funcional.

Antes de modificar cualquier archivo de código fuente, clasifica cada problema encontrado en una de estas dos categorías:
🔴 ERROR DE COMPILACIÓN — corregir siempre
Son errores que impiden que el proyecto arranque, sin valor pedagógico:

Import faltante o incorrecto
Clase, método o variable referenciada que no existe en ningún archivo del proyecto
Error de sintaxis
Anotación con atributos inválidos
Dependencia ausente en pom.xml, package.json, etc.
Archivo referenciado que no existe y debe ser creado con implementación mínima

→ CORREGIR estos errores.
🟡 PROBLEMA FUNCIONAL O DE CALIDAD — preservar siempre
Son problemas que no impiden compilar. Pueden ser intencionales para el aprendizaje:

Clave secreta hardcodeada ("secret", "password123")
API deprecada que funciona pero tiene reemplazo moderno
Lógica de negocio incorrecta o incompleta
Código redundante o de baja legibilidad
Falta de validaciones en flujo de negocio
Patrones de diseño incorrectos pero funcionales
Concurrencia no segura
Configuración funcional pero no óptima

→ PRESERVAR tal cual. No corregir, no mejorar, no comentar.
PASO 4 — Procesamiento según tipo de archivo
Tipo A — Código fuente
Aplica únicamente las correcciones clasificadas como 🔴 ERROR DE COMPILACIÓN.
No alteres ningún elemento clasificado como 🟡 PROBLEMA FUNCIONAL O DE CALIDAD.
Si falta un archivo referenciado, créalo con la implementación mínima necesaria para compilar.
Tipo B — Configuración / documentación
Extrae el contenido tal cual, sin modificaciones salvo errores evidentes de sintaxis
(ej: YAML mal indentado).
Tipo C — Excel (.xlsx)
Si viene con contenido real, genera el archivo respetando ese contenido.
Si viene con descripción en lenguaje natural, genera un archivo Excel funcional con:

Fila de encabezados en negrita con color de fondo distintivo
Columnas con ancho ajustado al contenido
Tipos de dato correctos por columna
Validaciones si la descripción lo indica
Hojas nombradas descriptivamente si hay más de una
Filas de ejemplo si no hay datos reales

Tipo D — Word (.docx)
Si viene con contenido real, genera el archivo respetando ese contenido.
Si viene con descripción en lenguaje natural, genera un documento Word funcional con:

Estilos de título (Título 1, Título 2) para jerarquía de secciones
Fuente legible (Calibri o equivalente), tamaño 11-12pt para cuerpo
Márgenes estándar
Tabla de contenido si tiene múltiples secciones
Tablas con encabezados en negrita si aplica

Tipo E — Otro
Genera el archivo con el contenido o estructura más apropiada según la descripción.
PASO 5 — Exportación en ZIP
Empaqueta todos los archivos en un único archivo ZIP descargable respetando exactamente
la estructura de rutas indicada por los marcadores.
El ZIP debe incluir:

Archivos de código con únicamente los errores de compilación corregidos
Archivos de configuración y documentación sin cambios
Archivos nuevos creados para resolver dependencias de compilación faltantes
Archivos Excel y Word generados desde descripción

IMPORTANTE: El ZIP debe estar listo para descargar al finalizar. No preguntes si el usuario
quiere generarlo. Simplemente genera el archivo y proporciona el enlace de descarga; No debes desplegar en el chat el resumen de lo que arreglaste al Zip, solo entregalo.

REGLAS IMPORTANTES

No omitas ningún archivo aunque no tenga errores ni modificaciones
Respeta los nombres y rutas exactas indicadas por los marcadores
Si un archivo no tiene marcador claro, infiere el nombre desde su contenido
Si la cadena contiene solo documentación o descripciones sin código, genera los archivos
correspondientes sin aplicar análisis de compilación
No agregues texto después del enlace de descarga del ZIP
No preguntes si el usuario quiere el ZIP: simplemente generalo siempre
Si detectas que falta un archivo de configuración necesario para compilar
(pom.xml, package.json, requirements.txt, build.gradle, etc.), créalo e inclúyelo
inferiendo su contenido desde los imports y frameworks detectados en el código
Nunca corrijas problemas 🟡 aunque parezcan obvios o fáciles de mejorar.
El participante que recibirá este proyecto los debe encontrar y resolver él mismo.


INPUT
Aquí está la cadena con los archivos:
// === ARCHIVO: src/main.cpp ===
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

// === ARCHIVO: src/models/objLoader.cpp ===
#include "objLoader.h"

Model loadModel(const std::string& path) {
    Model model;
    // Lógica para cargar modelo OBJ
    //...
    return model;
}

// === ARCHIVO: src/lights/lightManager.cpp ===
#include "lightManager.h"

void LightManager::addLight(const Light& light) {
    // Lógica para añadir luz
    //...
}

// === ARCHIVO: src/render/renderer.cpp ===
#include "renderer.h"

void Renderer::init(GLFWwindow* window) {
    // Lógica para inicializar renderizador
    //...
}

void Renderer::render(const Model& model, const LightManager& lightManager) {
    // Lógica para renderizar escena
    //...
}

// === ARCHIVO: src/optimization/optimization.cpp ===
#include "optimization.h"

void applyOptimizations() {
    // Lógica para aplicar optimizaciones
    //...
}

// === ARCHIVO: include/objLoader.h ===
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

// === ARCHIVO: include/lightManager.h ===
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

// === ARCHIVO: include/renderer.h ===
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

// === ARCHIVO: include/optimization.h ===
#ifndef OPTIMIZATION_H
#define OPTIMIZATION_H

void applyOptimizations();

#endif

// === ARCHIVO: resources/model.obj ===
# Empty OBJ file for demonstration purposes
```
