#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

/**
 * Calcula a multiplicação entre duas matrizes.
 * @param la Número de linhas da matriz A
 * @param ca Número de colunas da matriz A
 * @param A Matriz envolvida na multiplicação
 * @param lb Número de linhas da matriz A
 * @param cb Número de colunas da matriz A
 * @param B Matriz envolvida na multiplicação
 * @param R Matriz com o resultado da multiplicação.
 * @param lr Número de linhas da matriz R (parâmetro opcional)
 * @param cr Número de colunas da matriz R (parâmetro opcional)
*/ 
void multiplyMatrices(int, int, const float*, int, int, const float*, float*, int*, int*);

/**
 * Constrói a matriz de rotação com base nos eixos X, Y e Z do sistema de coordenadas.  
 * @param x Eixo X do sistema de coordenadas.
 * @param y Eixo Y do sistema de coordenadas.
 * @param z Eixo Z do sistema de coordenadas.
 * @param m Matriz de rotação resultante.
*/
void buildRotMatrix(const float *x, const float *y, const float *z, float *m);

/**
 * Calcula o producto cruzado (cross product) de dois vetores.
 * @param a Vetor que é utilizado no cálculo
 * @param b Vetor que é utilizado no cálculo
 * @param res Vetor que armazena o resultado do produto cruzado.
*/
void cross(const float *a, const float *b, float *res);

/**
 * Normaliza um vetor.
 * @param a Vetor a ser normalizado.
*/
void normalize(float *a);

/**
 * Calcula a norma de um vetor.
 * @param a Vetor cuja norma vai ser calculada.
 * @return A norma do vetor.
*/
float length(float *a);

/**
 * Calcula o produto escalar entre dois vetores.
 * @param v1 Primeiro vetor.
 * @param v2 Segundo vetor.
 * @return O produto escalar entre os dois vetores.
*/
float dot(float* v1, float* v2);

/**
 * Calcula o ângulo entre dois vetores.
 * @param v1 Primeiro vetor.
 * @param v2 Segundo vetor.
 * @return O ângulo em radianos entre os dois vetores.
*/
float angleVectors(float* v1, float* v2);

/**
 * Calcula o ponto da curva de Catmull-Rom para um valor de t específico.
 * @param t Valor de t (0 a 1) para a curva de Catmull-Rom.
 * @param p0 Primeiro ponto de controle da curva.
 * @param p1 Segundo ponto de controle da curva.
 * @param p2 Terceiro ponto de controle da curva.
 * @param p3 Quarto ponto de controle da curva.
 * @param pos Vetor que armazena o ponto resultante (se não desejar calcular, pode ser NULL).
 * @param deriv Vetor que armazena a derivada resultante (se não desejar calcular, pode ser NULL).
*/
void getCatmullRomPoint(float t, vector<float> p0, vector<float> p1, vector<float> p2, vector<float> p3, float *pos, float *deriv);

/**
 * Calcula o ponto global da curva de Catmull-Rom para um valor de t global.
 * @param gt Valor global de t (0 a tamanho do vetor de pontos de controle) para a curva de Catmull-Rom.
 * @param controlPoints Todos os pontos de controle da curva.
 * @param pos Vetor que armazena o ponto resultante.
 * @param deriv Vetor que armazena a derivada resultante.
*/
void getGlobalCatmullRomPoint(float gt, vector<vector<float>> controlPoints, float *pos, float *deriv);

/**
 * Calcula o ponto de superfície para uma curva bicúbica.
 * @param u Parâmetro u (0 a 1) para a curva bicúbica.
 * @param v Parâmetro v (0 a 1) para a curva bicúbica.
 * @param patch Matriz de pontos de controle da superfície bicúbica.
 * @param res Vetor que armazena o ponto de superfície resultante.
*/
void surfacePoint(float u, float v, vector<vector<float>> patch, float* res);
