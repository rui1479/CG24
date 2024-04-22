#include "../utils/primitive.hpp"
#include "../utils/point.hpp"
#include "../utils/list.hpp"
#include "plane.hpp"
#include "box.hpp"
#include "cone.hpp"
#include "sphere.hpp"
#include "ring.hpp"
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>


int main(int argc, char *argv[]) {
    if (argc >= 5) {
        Primitive primitive;
        const char *file_path;

        if (strcmp(argv[1], "plane") == 0) {
            int length = atoi(argv[2]), divisions = atoi(argv[3]);
            file_path = argv[4];

            // Generate the plane
            primitive = generatePlaneXZ(length, divisions, 0.0, 0);
        }
        else if (strcmp(argv[1], "box") == 0) {
            float length = atof(argv[2]);
            int divisions = atoi(argv[3]);
            file_path = argv[4];

            // Generate the box
            primitive = generateBox(length, divisions);
        }
        else if (strcmp(argv[1], "sphere") == 0) {
            float radius = atof(argv[2]);
            int slices = atoi(argv[3]), stacks = atoi(argv[4]);
            file_path = argv[5];
            printf("Sphere radius: %f\n", radius);
            // Generate the sphere
            primitive = generateSphere(radius, slices, stacks);
        }
        else if (strcmp(argv[1], "cone") == 0) {
           int radius = atoi(argv[2]), height = atoi(argv[3]), slices = atoi(argv[4]), stacks = atoi(argv[5]);
            file_path = argv[6];

            // Generate the cone
            primitive = generateCone(radius, height, slices, stacks);
        }
        else if (strcmp(argv[1], "ring") == 0) {
           float innerRadius = atof(argv[2]), outerRadius = atof(argv[3]), slices = atoi(argv[4]), stacks = atoi(argv[5]);
            file_path = argv[6];

            // Generate the cone
            primitive = generateRing(innerRadius, outerRadius, slices, stacks);
        }
        else {
            // Invalid shape
            std::cerr << "Invalid shape." << std::endl;
            return 1;
        }

        primitiveToFile(primitive, file_path);
        //freePri(primitive);
    }
    else {
        // Invalid number of arguments
        std::cerr << "Invalid number of arguments." << std::endl;
        return 1;
    }

    return 0;
}
