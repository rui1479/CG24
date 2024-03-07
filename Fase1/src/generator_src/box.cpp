#include "plane.hpp"
#include <algorithm>


Primitive generateBox(int length, int divisions){
    Primitive box = newEmptyPrimitive();
    if (box){// se deu NULL, é porque houve erros
        float dimension2 = (float)length / 2; //, div_side = (float)length/divisions;
        Primitive faceCima, faceBaixo, faceLateral1, faceLateral2, faceLateral3, faceLateral4;
        faceCima = generatePlaneXZ(length, divisions, dimension2, 0);
        faceBaixo = generatePlaneXZ(length, divisions, -dimension2, 1);
        faceLateral1 = generatePlaneXY(length, divisions, -dimension2, 0);
        faceLateral2 = generatePlaneXY(length, divisions, dimension2, 1);
        faceLateral3 = generatePlaneYZ(length, divisions, -dimension2, 0);
        faceLateral4 = generatePlaneYZ(length, divisions, dimension2, 1);
        addPontos(box, faceCima);  // face de baixo do cubo
        addPontos(box, faceBaixo); // face de cima do cubo
        addPontos(box, faceLateral1);
        addPontos(box, faceLateral2);
        addPontos(box, faceLateral3);
        addPontos(box, faceLateral4);
        freePri(faceCima);
        freePri(faceBaixo);
        freePri(faceLateral1);
        freePri(faceLateral2);
        freePri(faceLateral3);
        freePri(faceLateral4);
    }
    return box;
}
