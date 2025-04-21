#include "../../include/minirt.h"

//	=== Function Declarations ===

t_color	add_colors(t_color c1, t_color c2);
t_color	subtract_colors(t_color c1, t_color c2);
t_color	multiply_color_by_scalar(t_color c, double scalar);
t_color	divide_color_by_scalar(t_color c, double scalar);
t_color	hadamard_product(t_color c1, t_color c2);

//	=== Function Definitions ===

/**
 * @brief Adds two colors together.
 * 
 * @param c1 The first color.
 * @param c2 The second color.
 * 
 * @return A t_color structure representing the sum of the two colors.
 */
t_color	add_colors(t_color c1, t_color c2)
{
	t_color	result;

	result.r = c1.r + c2.r;
	result.g = c1.g + c2.g;
	result.b = c1.b + c2.b;
	return (result);
}

/**
 * @brief Subtracts the second color from the first color.
 * 
 * @param c1 The first color.
 * @param c2 The second color.
 * 
 * @return A t_color structure representing the difference of the two colors.
 */
t_color	subtract_colors(t_color c1, t_color c2)
{
	t_color	result;

	result.r = c1.r - c2.r;
	result.g = c1.g - c2.g;
	result.b = c1.b - c2.b;
	return (result);
}

/**
 * @brief Multiplies a color by a scalar value.
 * 
 * @param c The color to be multiplied.
 * @param scalar The scalar value.
 * 
 * @return A t_color structure representing the product of the color and scalar.
 */
t_color	multiply_color_by_scalar(t_color c, double scalar)
{
	t_color	result;

	result.r = c.r * scalar;
	result.g = c.g * scalar;
	result.b = c.b * scalar;
	return (result);
}

/**
 * @brief Divides a color by a scalar value.
 * 
 * @param c The color to be divided.
 * @param scalar The scalar value.
 * 
 * @return A t_color structure representing the quotient of the color and scalar.
 */
t_color	divide_color_by_scalar(t_color c, double scalar)
{
	t_color	result;

	result.r = c.r / scalar;
	result.g = c.g / scalar;
	result.b = c.b / scalar;
	return (result);
}

/**
 * @brief Computes the Hadamard product of two colors.
 * 
 * @param c1 The first color.
 * @param c2 The second color.
 * 
 * @return A t_color struct representing the Hadamard product of the two colors
 * @note The Hadamard product is the element-wise multiplication of two colors.
 * 	 It is used in graphics to combine colors
 *   in a way that preserves their individual components.
 */
t_color	hadamard_product(t_color c1, t_color c2)
{
	t_color	result;

	result.r = c1.r * c2.r;
	result.g = c1.g * c2.g;
	result.b = c1.b * c2.b;
	return (result);
}
