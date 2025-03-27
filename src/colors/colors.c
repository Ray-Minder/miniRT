#include "../../include/minirt.h"

t_color	color(uint8_t r, uint8_t g, uint8_t b);
t_color	add_colors(t_color c1, t_color c2);
t_color	subtract_colors(t_color c1, t_color c2);
t_color	multiply_color_by_scalar(t_color c, double scalar);
t_color	divide_color_by_scalar(t_color c, double scalar);
t_color	hadamard_product(t_color c1, t_color c2);

t_color	color(uint8_t r, uint8_t g, uint8_t b)
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
