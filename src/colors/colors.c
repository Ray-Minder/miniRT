#include "../../include/minirt.h"

//	=== Function Declarations ===

t_color		color(double r, double g, double b);
uint32_t	color_to_uint32(t_color color);

//	=== Function Definitions ===

/**
 * @brief Creates a color with the given red, green, and blue components.
 * 
 * @param r The red component (0.0 to 1.0).
 * @param g The green component (0.0 to 1.0).
 * @param b The blue component (0.0 to 1.0).
 * @return A t_color structure representing the color.
 */
t_color	color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

/**
 * @brief Converts a t_color structure to a uint32_t representation.
 * 
 * @param color The color to be converted.
 * 
 * @return A uint32_t representation of the color.
 * @note The color is represented in RGBA format,
 * 		where the alpha channel is set to 255.
 */
uint32_t	color_to_uint32(t_color color)
{
	uint32_t	result;

	if (color.r > 1.0)
		color.r = 1.0;
	if (color.g > 1.0)
		color.g = 1.0;
	if (color.b > 1.0)
		color.b = 1.0;
	result = ((uint32_t)(color.r * 255) << 24)
		| ((uint32_t)(color.g * 255) << 16)
		| (uint32_t)(color.b * 255) << 8
		| 0xFF;
	return (result);
}
