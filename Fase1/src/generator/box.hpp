#ifndef GENERATE_BOX_HPP
#define GENERATE_BOX_HPP

#include "../utils/primitive.hpp"

/**
 * @brief Generates a box primitive.
 *
 * This function generates a box primitive with the specified side length and number of divisions.
 * The resulting box is centered at the origin.
 *
 * @param length The side length of the box.
 * @param divisions The number of divisions along each side.
 *
 * @return A Primitive object representing the generated box.
 *
 * @note The generated box is centered at the origin.
 *
 * @see Primitive
 */
Primitive generateBox(int length, int divisions);


#endif // GENERATE_BOX_HPP
