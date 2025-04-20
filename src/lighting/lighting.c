#include "../../include/minirt.h"

//	=== Function Declarations ===

t_color	lighting(t_scene *scene, t_comps *comps);
t_color ambient_lighting(t_ambient_light ambient_light, t_color object_color);
t_color diffuse_lighting(t_light light, t_tuple normal, t_tuple position, t_color object_color);

//	=== Function Definitions ===

t_color	lighting(t_scene *scene, t_comps *comps)
{
	t_color	ambient_contribution;
	t_color	diffuse_contribution;

	ambient_contribution = ambient_lighting(scene->ambient_light, comps->object->color);
	diffuse_contribution = diffuse_lighting(scene->light, comps->normalv, comps->point, comps->object->color);
	return (add_colors(ambient_contribution, diffuse_contribution));
}

t_color ambient_lighting(t_ambient_light ambient_light, t_color object_color)
{
	t_color ambient;

	ambient = multiply_color_by_scalar(ambient_light.color, ambient_light.brightness);
	ambient = hadamard_product(ambient, object_color);
	return (ambient);
}

t_color diffuse_lighting(t_light light, t_tuple normal, t_tuple position, t_color object_color)
{
	t_color	diffuse;
	t_tuple	light_direction;
	double	light_dot_normal;
	
	light_direction = normalize_tuple(subtract_tuples(light.position, position));
	light_dot_normal = dot_product(normal, light_direction);
	// printf("Light dot normal = %f\n", light_dot_normal);
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
