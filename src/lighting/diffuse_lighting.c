#include "../../include/minirt.h"

t_color diffuse_lighting(t_light light, t_tuple normal, t_tuple position, t_color object_color)
{
	t_color	diffuse;
	t_tuple	light_direction;
	double	light_dot_normal;
	
	light_direction = normalize_tuple(subtract_tuples(light.position, position));
	light_dot_normal = dot_product(normal, light_direction);
	printf("Light dot normal = %f\n", light_dot_normal);
	if (light_dot_normal < 0)
	{
		diffuse = color(0, 0, 0);
	}
	else
	{
		diffuse = multiply_color_by_scalar(object_color, light.brightness * light_dot_normal);
		diffuse = hadamard_product(diffuse, light.color);
	}
	return (diffuse);
}
