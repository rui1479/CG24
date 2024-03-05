#include "plane.hpp"

Primitive generatePlaneXZ(int length, int divisions){
    float h = 0.0f;
    int baixo = 0;
    Primitive plano = newEmptyPrimitive();
    if (plano){ // se deu NULL, é porque houve erros
        float dimension2 = (float)length / 2, div_side = (float)length / divisions,
              x1 = -dimension2, z1 = -dimension2,
              x2 = -dimension2, z2 = -dimension2 + div_side,
              x3 = -dimension2 + div_side, z3 = -dimension2,
              x4 = -dimension2 + div_side, z4 = -dimension2 + div_side;
        float arrx[4] = {x1, x2, x3, x4};
        float arrz[4] = {z1, z2, z3, z4};

        // float arrx[4] = {x1,x3,x2,x4};
        // float arrz[4] = {z1,z3,z2,z4};
        if (baixo == 1){
            arrx[1] = x3;
            arrx[2] = x2;
            arrz[1] = z3;
            arrz[2] = z2;
        }

        for (int linha = 0; linha < divisions; linha++){
            for (int coluna = 0; coluna < divisions; coluna++){
                // Primeiro triângulo do quadrado
                addValueList(getPontos(plano), newPoint(arrx[0] + coluna * div_side, h, arrz[0]));
                addValueList(getPontos(plano), newPoint(arrx[1] + coluna * div_side, h, arrz[1]));
                addValueList(getPontos(plano), newPoint(arrx[2] + coluna * div_side, h, arrz[2]));
 
                // Segundo triângulo do quadrado
                addValueList(getPontos(plano), newPoint(arrx[1] + coluna * div_side, h, arrz[1]));
                addValueList(getPontos(plano), newPoint(arrx[3] + coluna * div_side, h, arrz[3]));
                addValueList(getPontos(plano), newPoint(arrx[2] + coluna * div_side, h, arrz[2]));
            }
            arrz[0] += div_side;arrz[1] += div_side;arrz[2] += div_side;arrz[3] += div_side;
        }
    }
    return plano;
}