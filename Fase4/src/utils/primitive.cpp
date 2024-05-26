#include "primitive.hpp"
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

struct primitive {
    List pontos;
    List normais;
    List textCoords;
    char* textureFile;
    vector<float>* diffuse;
    vector<float>* ambient;
    vector<float>* specular;
    vector<float>* emissive;
    float shininess;
    
    
};

// Constructors
Primitive newEmptyPrimitive() {
    Primitive pri = (Primitive)malloc(sizeof(struct primitive));
    if (pri) {
        pri->pontos = newL();
        pri->normais = newL();
        pri->textCoords = newL();
        pri->diffuse = new vector<float>({200.0f, 200.0f, 200.0f, 1.0f});
        pri->ambient = new vector<float>({50.0f, 50.0f, 50.0f, 1.0f});
        pri->specular = new vector<float>({0.0f, 0.0f, 0.0f, 1.0f});
        pri->emissive = new vector<float>({0.0f, 0.0f, 0.0f, 1.0f});
        pri->textureFile = NULL;
        pri->shininess = 0.0f;
    }
    return pri;
}

Primitive newPrimitiveFromList(List pontos) {
    Primitive pri = newEmptyPrimitive();
    List temp = pontos;
    if (pri) {
        while (temp) {
            addValueList(pri->pontos, getData(temp));
            temp = getNext(temp);
        }
    }
    return pri;
}

// Getters
List getPontos(Primitive pri) {
    if (pri) {
        return pri->pontos;
    }
    return NULL;
}

// Add Points
void addPontos(Primitive f, Primitive toAdd) {
    if (f) {
        List pontos = toAdd->pontos;
        for (unsigned long i = 0; i < calculateLength(pontos); i++) {
            addValueList(f->pontos, getDataByIndex(pontos, i));
        }
    }
}

void addPonto(Primitive f, Point p) {
    if (f) {
        addValueList(f->pontos, p);
    }
}

void addPontoArr(Primitive f, float* p) {
    addPonto(f, newPoint(p[0], p[1], p[2]));
}

// Add PNT
void addPNT(Primitive f, Point ponto, Point normal, Point textCoord) {
    addPonto(f, ponto);
    addValueList(f->normais, normal);
    if (textCoord) {
        addValueList(f->textCoords, textCoord);
    } else {
        addValueList(f->textCoords, newPoint2f(0, 0));
    }
}

void addPNTArr(Primitive f, float* ponto, float* normal, float* textCoord) {
    addPontoArr(f, ponto);
    normalize(normal);
    addValueList(f->normais, newPoint(normal[0], normal[1], normal[2]));
    if (textCoord) {
        addValueList(f->textCoords, newPoint2f(textCoord[0], textCoord[1]));
    } else {
        addValueList(f->textCoords, newPoint2f(0, 0));
    }
}

// Set and Get Color Properties
void setDiffuse(Primitive f, float r, float g, float b) {
    float* aux = f->diffuse->data();
    aux[0] = r;
    aux[1] = g;
    aux[2] = b;
}

vector<float> getDiffuse(Primitive f) {
    vector<float> result;
    result.push_back(f->diffuse->at(0) / 255.0f);
    result.push_back(f->diffuse->at(1) / 255.0f);
    result.push_back(f->diffuse->at(2) / 255.0f);
    result.push_back(f->diffuse->at(3) / 255.0f);
    return result;
}

void setAmbient(Primitive f, float r, float g, float b) {
    float* aux = f->ambient->data();
    aux[0] = r;
    aux[1] = g;
    aux[2] = b;
}

vector<float> getAmbient(Primitive f) {
    vector<float> result;
    result.push_back(f->ambient->at(0) / 255.0f);
    result.push_back(f->ambient->at(1) / 255.0f);
    result.push_back(f->ambient->at(2) / 255.0f);
    result.push_back(f->ambient->at(3) / 255.0f);
    return result;
}

void setSpecular(Primitive f, float r, float g, float b) {
    float* aux = f->specular->data();
    aux[0] = r;
    aux[1] = g;
    aux[2] = b;
}

vector<float> getSpecular(Primitive f) {
    vector<float> result;
    result.push_back(f->specular->at(0) / 255.0f);
    result.push_back(f->specular->at(1) / 255.0f);
    result.push_back(f->specular->at(2) / 255.0f);
    result.push_back(f->specular->at(3) / 255.0f);
    return result;
}

void setEmissive(Primitive f, float r, float g, float b) {
    float* aux = f->emissive->data();
    aux[0] = r;
    aux[1] = g;
    aux[2] = b;
}

vector<float> getEmissive(Primitive f) {
    vector<float> result;
    result.push_back(f->emissive->at(0) / 255.0f);
    result.push_back(f->emissive->at(1) / 255.0f);
    result.push_back(f->emissive->at(2) / 255.0f);
    result.push_back(f->emissive->at(3) / 255.0f);
    return result;
}

void setShininess(Primitive f, float shininess) {
    f->shininess = shininess;
}

float getShininess(Primitive f) {
    return f->shininess;
}

void setTextureFile(Primitive f, const char* textFile) {
    f->textureFile = strdup(textFile);
}

const char* getTextureFile(Primitive f) {
    return f->textureFile;
}

// Serialization and Deserialization
void primitiveToFile(Primitive pri, const char* path) {
    if (!pri || !pri->pontos || !path) {
        printf("Impossível criar ficheiro devido a argumentos inválidos\n");
        return;
    }

    FILE* file = fopen(path, "w");
    if (!file) {
        printf("Ocorreu um erro na abertura do ficheiro '%s'\n", path);
        return;
    }

    fprintf(file, "%lu\n", calculateLength(pri->pontos));

    List temp = pri->pontos;
    List tempNormais = pri->normais;
    List tempTextCoords = pri->textCoords;

    while (temp && tempNormais && tempTextCoords) {
        Point p = (Point)getData(temp);
        Point n = (Point)getData(tempNormais);
        Point tc = (Point)getData(tempTextCoords);
        if (p && n && tc) {
            fprintf(file, "%.3f,%.3f,%.3f ; %.3f,%.3f,%.3f ; %.3f,%.3f\n", getX(p), getY(p), getZ(p), getX(n), getY(n), getZ(n), getX(tc), getY(tc));
        }
        temp = getNext(temp);
        tempNormais = getNext(tempNormais);
        tempTextCoords = getNext(tempTextCoords);
    }

    fclose(file);
}

Primitive fileToPrimitive(const char* path) {
    Primitive pri = newEmptyPrimitive();
    FILE* file = fopen(path, "r");

    if (!pri || !file) {
        printf("Impossível ler o arquivo '%s'\n", path);
        return pri;
    }

    int vertices;
    if (fscanf(file, "%d", &vertices) != 1) {
        printf("Formato do arquivo inválido\n");
        fclose(file);
        return pri;
    }

    float xp, yp, zp, xn, yn, zn, xtc, ytc;
    for (int i = 0; i < vertices; i++) {
        if (fscanf(file, "%f,%f,%f ; %f,%f,%f ; %f,%f", &xp, &yp, &zp, &xn, &yn, &zn, &xtc, &ytc) == 8) {
            addPNT(pri, newPoint(xp, yp, zp), newPoint(xn, yn, zn), newPoint(xtc, ytc, 0.0f));
        } else {
            printf("Formato de dados inválido na linha %d\n", i + 2);
        }
    }

    fclose(file);
    return pri;
}

// Utility functions
float arred(float num) {
    long double places = 4.0;
    long double pow10 = std::pow(10.0, places);
    return std::round(num * pow10) / pow10;
}

// Memory Management
void freePri(Primitive pri) {
    if (!pri || !pri->pontos) {
        printf("Impossível deletar a primitiva devido a argumentos inválidos\n");
        return;
    }

    List temp = pri->pontos;
    while (temp) {
        freeP((Point)getData(temp));
        temp = getNext(temp);
    }

    freeL(pri->pontos);
    freeL(pri->normais);
    freeL(pri->textCoords);

    delete pri->diffuse;
    delete pri->ambient;
    delete pri->specular;
    delete pri->emissive;
    free(pri->textureFile);

    pri->pontos = NULL;
    pri->normais = NULL;
    pri->textCoords = NULL;

    free(pri);
}
