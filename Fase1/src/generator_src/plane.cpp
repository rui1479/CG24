#include "plane.hpp"
#include <algorithm>

Primitive generatePlaneXZ(int length, int divisions, float h = 0.0f, int bottom = 0) {
    Primitive plano = newEmptyPrimitive();

    if (plano) {
        float dimension2 = static_cast<float>(length) / 2;
        float div_side = static_cast<float>(length) / divisions;

        for (int linha = 0; linha < divisions; linha++) {
            for (int coluna = 0; coluna < divisions; coluna++) {
                float x1 = -dimension2 + coluna * div_side;
                float z1 = -dimension2 + linha * div_side;

                float x2 = x1;
                float z2 = z1 + div_side;

                float x3 = x1 + div_side;
                float z3 = z1;

                float x4 = x1 + div_side;
                float z4 = z1 + div_side;
                
                if (bottom == 1) {
                    std::swap(z1, z3);
                    std::swap(z2, z4);
                }

                // Primeiro triângulo do quadrado
                addValueList(getPontos(plano), newPoint(x1, h, z1));
                addValueList(getPontos(plano), newPoint(x2, h, z2));
                addValueList(getPontos(plano), newPoint(x3, h, z3));

                // Segundo triângulo do quadrado
                addValueList(getPontos(plano), newPoint(x2, h, z2));
                addValueList(getPontos(plano), newPoint(x4, h, z4));
                addValueList(getPontos(plano), newPoint(x3, h, z3));
            }
        }
    }

    return plano;
}


Primitive generatePlaneXY(int length, int divisions, float h = 0.0f, int face = 0) {
    Primitive plano = newEmptyPrimitive();

    if (plano) {
        float dimension2 = static_cast<float>(length) / 2;
        float div_side = static_cast<float>(length) / divisions;

        for (int linha = 0; linha < divisions; linha++) {
            for (int coluna = 0; coluna < divisions; coluna++) {
                float x1 = -dimension2 + coluna * div_side;
                float y1 = -dimension2 + linha * div_side;

                float x2 = x1;
                float y2 = y1 + div_side;

                float x3 = x1 + div_side;
                float y3 = y1;

                float x4 = x1 + div_side;
                float y4 = y1 + div_side;

                if (face == 1) {
                    std::swap(y1, y3);
                    std::swap(y2, y4);
                }

                // Primeiro triângulo do quadrado
                addValueList(getPontos(plano), newPoint(x1, y1, h));
                addValueList(getPontos(plano), newPoint(x2, y2, h));
                addValueList(getPontos(plano), newPoint(x3, y3, h));

                // Segundo triângulo do quadrado
                addValueList(getPontos(plano), newPoint(x2, y2, h));
                addValueList(getPontos(plano), newPoint(x4, y4, h));
                addValueList(getPontos(plano), newPoint(x3, y3, h));
            }
        }
    }

    return plano;
}


Primitive generatePlaneYZ(int length, int divisions, float w = 0.0f, int face = 0) {
    Primitive plano = newEmptyPrimitive();

    if (plano) {
        float dimension2 = static_cast<float>(length) / 2;
        float div_side = static_cast<float>(length) / divisions;

        for (int linha = 0; linha < divisions; linha++) {
            for (int coluna = 0; coluna < divisions; coluna++) {
                float y1 = -dimension2 + linha * div_side;
                float z1 = -dimension2 + coluna * div_side;

                float y2 = y1;
                float z2 = z1 + div_side;

                float y3 = y1 + div_side;
                float z3 = z1;

                float y4 = y1 + div_side;
                float z4 = z1 + div_side;

                if (face == 1) {
                    std::swap(z1, z3);
                    std::swap(z2, z4);
                }

                // Primeiro triângulo do quadrado
                addValueList(getPontos(plano), newPoint(w, y1, z1));
                addValueList(getPontos(plano), newPoint(w, y2, z2));
                addValueList(getPontos(plano), newPoint(w, y3, z3));

                // Segundo triângulo do quadrado
                addValueList(getPontos(plano), newPoint(w, y2, z2));
                addValueList(getPontos(plano), newPoint(w, y4, z4));
                addValueList(getPontos(plano), newPoint(w, y3, z3));
            }
        }
    }

    return plano;
}
