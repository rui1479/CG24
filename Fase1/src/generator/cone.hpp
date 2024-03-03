#ifndef GENERATE_CONE_HPP
#define GENERATE_CONE_HPP

#include "../utils/primitive.hpp"

/**
 * @brief Generates a cone primitive.
 *
 * This function generates a cone primitive with the specified base radius, height,
 * number of slices, and number of stacks. The resulting cone is centered at the origin.
 *
 * @param radius The radius of the cone's base.
 * @param height The height of the cone.
 * @param slices The number of longitudinal slices (horizontal divisions).
 * @param stacks The number of latitudinal stacks (vertical divisions).
 *
 * @return A Primitive object representing the generated cone.
 *
 * @note The generated cone is centered at the origin.
 *
 * @see Primitive
 */
Primitive generateCone(int radius, int height, int slices, int stacks);


#endif // GENERATE_CONE_HPP
