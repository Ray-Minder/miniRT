#include "../../include/minirt.h"

//	=== Function Declarations ===

t_color	color(double r, double g, double b);
t_color	add_colors(t_color c1, t_color c2);
t_color	subtract_colors(t_color c1, t_color c2);
t_color	multiply_color_by_scalar(t_color c, double scalar);
t_color	divide_color_by_scalar(t_color c, double scalar);
t_color	hadamard_product(t_color c1, t_color c2);

//	=== Function Definitions ===

t_color	color(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	add_colors(t_color c1, t_color c2)
{
	t_color result;

	result.r = c1.r + c2.r;
	result.g = c1.g + c2.g;
	result.b = c1.b + c2.b;
	return (result);
}

t_color	subtract_colors(t_color c1, t_color c2)
{
	t_color result;

	result.r = c1.r - c2.r;
	result.g = c1.g - c2.g;
	result.b = c1.b - c2.b;
	return (result);
}

t_color	multiply_color_by_scalar(t_color c, double scalar)
{
	t_color result;

	result.r = c.r * scalar;
	result.g = c.g * scalar;
	result.b = c.b * scalar;
	return (result);
}

t_color	divide_color_by_scalar(t_color c, double scalar)
{
	t_color result;

	result.r = c.r / scalar;
	result.g = c.g / scalar;
	result.b = c.b / scalar;
	return (result);
}

t_color	hadamard_product(t_color c1, t_color c2)
{
	t_color result;

	result.r = c1.r * c2.r;
	result.g = c1.g * c2.g;
	result.b = c1.b * c2.b;
	return (result);
}

uint32_t	color_to_uint32(t_color color)
{
	uint32_t result;

	if (color.r > 1.0)
		color.r = 1.0;
	if (color.g > 1.0)
		color.g = 1.0;
	if (color.b > 1.0)
		color.b = 1.0;
	result = ((uint32_t)(color.r * 255) << 24) | ((uint32_t)(color.g * 255) << 16) | (uint32_t)(color.b * 255) << 8 | 0xFF;
	return (result);
}
