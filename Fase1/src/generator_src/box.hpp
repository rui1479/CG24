#ifndef BOX
#define BOX

#include "../utils/list.hpp"
#include "../utils/point.hpp"
#include "../utils/primitive.hpp"
#include "plane.hpp"

Primitive generateBox(int dimension, int divisionsPerEdge);

#endif