#include "light.hpp"
#include <vector>
#include <cstdlib>

struct light {
    char type; // 'p': point, 'd': directional, 's': spotlight
    std::vector<float>* pos;
    std::vector<float>* dir;
    float cutoff;
};

Light newEmptyLight() {
    Light res = (Light)malloc(sizeof(struct light));
    if (res) {
        res->type = 0;

        res->pos = new std::vector<float>();
        res->dir = new std::vector<float>();

        res->pos->push_back(0.0f);
        res->pos->push_back(0.0f);
        res->pos->push_back(0.0f);
        res->pos->push_back(1.0f); // é um ponto

        res->dir->push_back(0.0f);
        res->dir->push_back(0.0f);
        res->dir->push_back(0.0f);
        res->dir->push_back(0.0f); // é um vector

        res->cutoff = 0.0f;
    }
    return res;
}

Light newLight(char type, float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float cutoff) {
    Light res = newEmptyLight();
    if (res) {
        res->type = type;
        setLightPos(res, posX, posY, posZ);
        setLightDir(res, dirX, dirY, dirZ);
        res->cutoff = cutoff;
    }
    return res;
}

Light newLight2(char type, float* pos, float* dir, float cutoff) {
    Light res = newEmptyLight();
    if (res) {
        res->type = type;
        setLightPosArr(res, pos);
        setLightDirArr(res, dir);
        res->cutoff = cutoff;
    }
    return res;
}

void setLightType(Light l, char type) {
    if (l) {
        l->type = type;
    }
}

void setLightPos(Light l, float x, float y, float z) {
    if (l && l->pos) {
        float* posArr = l->pos->data();
        posArr[0] = x;
        posArr[1] = y;
        posArr[2] = z;
    }
}

void setLightPosArr(Light l, float* pos) {
    if (l && pos) {
        setLightPos(l, pos[0], pos[1], pos[2]);
    }
}

void setLightDir(Light l, float x, float y, float z) {
    if (l && l->dir) {
        float* dirArr = l->dir->data();
        dirArr[0] = x;
        dirArr[1] = y;
        dirArr[2] = z;
    }
}

void setLightDirArr(Light l, float* dir) {
    if (l && dir) {
        setLightDir(l, dir[0], dir[1], dir[2]);
    }
}

void setLightCutoff(Light l, float cutoff) {
    if (l) {
        l->cutoff = cutoff;
    }
}

char getLightType(Light l) {
    if (l) {
        return l->type;
    }
    return 0;
}

std::vector<float> getLightPos(Light l) {
    std::vector<float> pos;
    if (l && l->pos) {
        for (int i = 0; i < 4; i++) {
            pos.push_back(l->pos->at(i));
        }
    }
    return pos;
}

std::vector<float> getLightDir(Light l) {
    std::vector<float> dir;
    if (l && l->dir) {
        for (int i = 0; i < 4; i++) {
            dir.push_back(l->dir->at(i));
        }
    }
    return dir;
}

float getLightCutoff(Light l) {
    if (l) {
        return l->cutoff;
    }
    return 0.0f;
}
