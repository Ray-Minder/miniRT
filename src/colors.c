#include "../include/colors.h"

t_tuple	color(double r, double g, double b);
t_tuple	add_colors(t_tuple c1, t_tuple c2);
t_tuple	subtract_colors(t_tuple c1, t_tuple c2);
t_tuple	multiply_color_by_scalar(t_tuple c, double scalar);
t_tuple	divide_color_by_scalar(t_tuple c, double scalar);
t_tuple	hadamard_product(t_tuple c1, t_tuple c2);

t_tuple	color(double r, double g, double b)
{
	t_tuple color;

	color.x = r;
	color.y = g;
	color.z = b;
	color.w = 0;
	return (color);
}

t_tuple	add_colors(t_tuple c1, t_tuple c2)
{
	t_tuple result;

	result.x = c1.x + c2.x;
	result.y = c1.y + c2.y;
	result.z = c1.z + c2.z;
	result.w = c1.w;
	return (result);
}

t_tuple	subtract_colors(t_tuple c1, t_tuple c2)
{
	t_tuple result;

	result.x = c1.x - c2.x;
	result.y = c1.y - c2.y;
	result.z = c1.z - c2.z;
	result.w = c1.w;
	return (result);
}

t_tuple	multiply_color_by_scalar(t_tuple c, double scalar)
{
	t_tuple result;

	result.x = c.x * scalar;
	result.y = c.y * scalar;
	result.z = c.z * scalar;
	result.w = c.w;
	return (result);
}

t_tuple	divide_color_by_scalar(t_tuple c, double scalar)
{
	t_tuple result;

	result.x = c.x / scalar;
	result.y = c.y / scalar;
	result.z = c.z / scalar;
	result.w = c.w;
	return (result);
}

t_tuple	hadamard_product(t_tuple c1, t_tuple c2)
{
	t_tuple result;

	result.x = c1.x * c2.x;
	result.y = c1.y * c2.y;
	result.z = c1.z * c2.z;
	result.w = c1.w;
	return (result);
}
