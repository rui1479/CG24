#ifndef GENERATE_PLANEXZ_HPP
#define GENERATE_PLANEXZ_HPP

#include "../utils/primitive.hpp"

/**
 * @brief Generates a plane primitive in the XZ plane.
 *
 * This function generates a plane primitive in the XZ plane with the specified side length
 * and number of divisions. The resulting plane is centered at the origin.
 *
 * @param length The side length of the square plane.
 * @param divisions The number of divisions along each side.
 *
 * @return A Primitive object representing the generated plane in the XZ plane.
 *
 * @note The generated plane is centered at the origin.
 *
 * @see Primitive
 */
Primitive generatePlaneXZ(int length, int divisions);


#endif // GENERATE_PLANEXZ_HPP
