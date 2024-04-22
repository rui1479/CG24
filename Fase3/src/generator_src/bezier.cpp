#include "bezier.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::vector<std::vector<float>>> readPatchesFile(const char* filePath) {
    std::vector<std::vector<std::vector<float>>> result;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo");
    }

    std::string line;
    // Obtenção do número de patches
    if (!std::getline(file, line)) {
        throw std::runtime_error("Erro ao ler o número de patches");
    }
    int numPatches = std::stoi(line);

    // Obtenção dos índices de cada patch
    std::vector<std::vector<int>> indicesPerPatch;
    for (int i = 0; i < numPatches; i++) {
        if (!std::getline(file, line)) {
            throw std::runtime_error("Erro ao ler os índices de patches");
        }
        std::istringstream iss(line);
        std::vector<int> indices;
        int index;
        while (iss >> index) {
            indices.push_back(index);
        }
        indicesPerPatch.push_back(indices);
    }

    // Obtenção do número de pontos de controle
    if (!std::getline(file, line)) {
        throw std::runtime_error("Erro ao ler o número de pontos de controle");
    }
    int numControlPoints = std::stoi(line);

    // Obtenção dos pontos de controle
    std::vector<std::vector<float>> controlPoints;
    for (int i = 0; i < numControlPoints; i++) {
        if (!std::getline(file, line)) {
            throw std::runtime_error("Erro ao ler os pontos de controle");
        }
        std::istringstream iss(line);
        std::vector<float> point;
        float coord;
        while (iss >> coord) {
            point.push_back(coord);
        }
        controlPoints.push_back(point);
    }

    // Construção dos patches
    for (const std::vector<int>& indices : indicesPerPatch) {
        std::vector<std::vector<float>> patch;
        for (int indice : indices) {
            patch.emplace_back(controlPoints[indice]);
        }
        result.push_back(patch);
    }
    return result;
}


Primitive generateSurface(const char* filePath, int tessellation) {
    Primitive result = newEmptyPrimitive();

    const float delta = 1.0f / tessellation;
    const auto& patches = readPatchesFile(filePath); // Usar referência constante

    for (const auto& patch : patches) {
        for (int i = 0; i < tessellation; ++i) {
            for (int j = 0; j < tessellation; ++j) {
                float u = i * delta;
                float v = j * delta;

                // Cálculo dos pontos
                float A[3], B[3], C[3], D[3];
                surfacePoint(u, v, patch, A);
                surfacePoint(u, v + delta, patch, B);
                surfacePoint(u + delta, v, patch, C);
                surfacePoint(u + delta, v + delta, patch, D);

                // Triangulação
                addPontoArr(result, C);
                addPontoArr(result, A);
                addPontoArr(result, B);

                addPontoArr(result, B);
                addPontoArr(result, D);
                addPontoArr(result, C);
            }
        }
    }
    return result;
}




