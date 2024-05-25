#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <vector>

struct light;
typedef struct light* Light;

Light newEmptyLight();
Light newLight(char type, float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float cutoff);
Light newLight2(char type, float* pos, float* dir, float cutoff);

void setLightType(Light l, char type);
void setLightPos(Light l, float x, float y, float z);
void setLightPosArr(Light l, float* pos);
void setLightDir(Light l, float x, float y, float z);
void setLightDirArr(Light l, float* dir);
void setLightCutoff(Light l, float cutoff);

char getLightType(Light l);
std::vector<float> getLightPos(Light l);
std::vector<float> getLightDir(Light l);
float getLightCutoff(Light l);

#endif // LIGHT_HPP
