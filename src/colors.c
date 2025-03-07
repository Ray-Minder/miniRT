#include "../include/colors.h"

t_tuple	color(double r, double g, double b)
{
	t_tuple color;

	color.x = r;
	color.y = g;
	color.z = b;
	color.w = 0;
	return (color);
}


