#include "../../include/minirt.h"

t_color	ambient_lighting(t_ambient_light ambient_light, t_color object_color)
{
	t_color	ambient;

	ambient = multiply_color_by_scalar(ambient_light.color, ambient_light.brightness);

	ambient = hadamard_product(ambient, object_color);
	return (ambient);
}

t_color	diffuse_lighting(t_light light, t_tuple normal, t_tuple position, t_color object_color)
{
	t_color	diffuse;
	// t_color scaled_color;
	t_tuple	light_direction;
	double	light_dot_normal;
	
	light_direction = normalize_tuple(subtract_tuples(light.position, position));
	light_dot_normal = dot_product(normal, light_direction);
	if (light_dot_normal < 0)
		diffuse = color(0, 0, 0);
	else
	{
		diffuse = multiply_color_by_scalar(object_color, light.brightness * light_dot_normal);
		diffuse = hadamard_product(diffuse, light.color);
	}

	return (diffuse);
}

// t_color lighting(t_light light, t_tuple normal, t_tuple light_position, t_color object_color)
// {
// 	t_color ambient;
// 	t_color diffuse;
// 	t_tuple	light_direction;
// 	double	light_dot_normal;

// 	// Ambient lighting
// 	ambient = ambient_lighting(, object_color);

// 	// Diffuse lighting
// 	light_direction = normalize_tuple(subtract_tuples(light_position, light.position));
// 	light_dot_normal = dot_product(normal, light_direction);
// 	if (light_dot_normal < 0)
// 		diffuse = color(0, 0, 0);
// 	else
// 		diffuse = multiply_color_by_scalar(object_color, light.brightness * light_dot_normal);

// 	// Combine ambient and diffuse
// 	return add_colors(ambient, diffuse);
// }