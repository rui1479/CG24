#include "ring.hpp"

Primitive generateRing(float innerRadius, float outerRadius, int slices, int stacks) {
    Primitive ring = newEmptyPrimitive();

    if (ring) {
        float phi, theta;
        float phiIncrement = M_PI / stacks;
        float thetaIncrement = 2.0 * M_PI / slices;

        for (int i = 0; i <= stacks; i++) {
            phi = i * phiIncrement;

            for (int j = 0; j < slices; j++) {
                theta = j * thetaIncrement;

                // Calculate the position of the point
                float x = cos(theta) * (outerRadius + innerRadius * cos(phi));
                float y = sin(theta) * (outerRadius + innerRadius * cos(phi));
                float z = innerRadius * sin(phi);

                addValueList(getPontos(ring), newPoint(x, y, z));
            }
        }

        // Connect the points to form triangles
        for (int i = 0; i < stacks; i++) {
            for (int j = 0; j < slices; j++) {
                int p1 = i * slices + j;
                int p2 = p1 + slices;

                // First triangle of the square
                addValueList(getPontos(ring), getDataByIndex(getPontos(ring), p1));
                addValueList(getPontos(ring), getDataByIndex(getPontos(ring), p1 + 1));
                addValueList(getPontos(ring), getDataByIndex(getPontos(ring), p2));

                // Second triangle of the square
                addValueList(getPontos(ring), getDataByIndex(getPontos(ring), p1 + 1));
                addValueList(getPontos(ring), getDataByIndex(getPontos(ring), p2 + 1));
                addValueList(getPontos(ring), getDataByIndex(getPontos(ring), p2));
            }
        }
    }

    return ring;
}
