#ifndef RING
#define RING

#include "../utils/list.hpp"
#include "../utils/point.hpp"
#include "../utils/primitive.hpp"

Primitive generateRing(float innerRadius, float outerRadius, int slices, int stacks);

#endif