#include "ring.hpp"
#include <iostream>

Primitive generateRing(float innerRadius, float outerRadius, int slices, int stacks) {
    Primitive ring = newEmptyPrimitive();

    if (ring) {
        float stack_width = static_cast<float>(outerRadius - innerRadius) / stacks;
        float slice_angle = 2.0 * M_PI / slices;

        for (int i = 0; i <= stacks; i++) {
            float r1 = innerRadius + i * stack_width;
            float r2 = innerRadius + (i + 1) * stack_width;

            for (int j = 0; j < slices; j++) {
                float angle1 = j * slice_angle;
                float angle2 = (j + 1) * slice_angle;

                // Calculate the position of the points
                float x1 = r1 * cos(angle1);
                float y1 = r1 * sin(angle1);

                float x2 = r1 * cos(angle2);
                float y2 = r1 * sin(angle2);

                float x3 = r2 * cos(angle1);
                float y3 = r2 * sin(angle1);

                float x4 = r2 * cos(angle2);
                float y4 = r2 * sin(angle2);

                // First triangle of the square
                addValueList(getPontos(ring), newPoint(x1, 0, y1));
                addValueList(getPontos(ring), newPoint(x2, 0, y2));
                addValueList(getPontos(ring), newPoint(x3, 0, y3));

                // Second triangle of the square
                addValueList(getPontos(ring), newPoint(x2, 0, y2));
                addValueList(getPontos(ring), newPoint(x4, 0, y4));
                addValueList(getPontos(ring), newPoint(x3, 0, y3));
            }
        }
    }

    return ring;
}
