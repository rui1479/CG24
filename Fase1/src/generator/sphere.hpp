#ifndef GENERATE_SPHERE_HPP
#define GENERATE_SPHERE_HPP

#include "../utils/primitive.hpp"

/**
 * @brief Generates a sphere primitive.
 *
 * This function generates a sphere primitive with the specified radius, number of slices,
 * and number of stacks. The resulting sphere is centered at the origin.
 *
 * @param radius The radius of the sphere.
 * @param slices The number of longitudinal slices (horizontal divisions).
 * @param stacks The number of latitudinal stacks (vertical divisions).
 *
 * @return A Primitive object representing the generated sphere.
 *
 * @note The generated sphere is centered at the origin.
 *
 * @see Primitive
 */
Primitive generateSphere(int radius, int slices, int stacks);


#endif // GENERATE_SPHERE_HPP
