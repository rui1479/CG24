#include "sphere.hpp"

Primitive generateSphere(float radius, int slices, int stacks) {
    Primitive sphere = newEmptyPrimitive();

    if (sphere) {
        float phi, theta;
        float phiIncrement = M_PI / stacks;
        float thetaIncrement = 2.0 * M_PI / slices;

        for (int i = 0; i <= stacks; i++) {
            phi = i * phiIncrement;

            for (int j = 0; j < slices; j++) {
                theta = j * thetaIncrement;

                float x = radius * sin(phi) * cos(theta);
                float y = radius * sin(phi) * sin(theta);
                float z = radius * cos(phi);

                addValueList(getPontos(sphere), newPoint(x, y, z));
            }
        }

        // Conectar os pontos para formar triângulos
        for (int i = 0; i < stacks; i++) {
            for (int j = 0; j < slices; j++) {
                int p1 = i * slices + j;
                int p2 = p1 + slices;

                // Primeiro triângulo do quadrado
                addValueList(getPontos(sphere), getDataByIndex(getPontos(sphere), p1));
                addValueList(getPontos(sphere), getDataByIndex(getPontos(sphere), p1 + 1));
                addValueList(getPontos(sphere), getDataByIndex(getPontos(sphere), p2));

                // Segundo triângulo do quadrado
                addValueList(getPontos(sphere), getDataByIndex(getPontos(sphere), p1 + 1));
                addValueList(getPontos(sphere), getDataByIndex(getPontos(sphere), p2 + 1));
                addValueList(getPontos(sphere), getDataByIndex(getPontos(sphere), p2));
            }
        }
    }

    return sphere;
}
