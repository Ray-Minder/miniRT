#include "../../include/minirt.h"

t_color shade_hit(t_scene *scene, t_comps *comps)
{
	t_color final_color;

	if (is_shadowed(scene, comps->over_point))
	{
		final_color = ambient_lighting(scene->ambient_light, comps->object->color);
	}
	else
		final_color = lighting(scene, comps);
	return (final_color);
}

bool is_shadowed(t_scene *scene, t_tuple over_point)
{
	t_tuple	light_vector;
	double	distance;
	t_ray	shadow_ray;
	t_x		*xs_list;
	t_x		*the_hit;

	light_vector = subtract_tuples(scene->light.position, over_point);
	light_vector.w = 0;
	distance = tuple_magnitude(light_vector);
	shadow_ray.origin = over_point;
	shadow_ray.direction = normalize_tuple(light_vector);
	// printf("Shadow ray:\n");
	// print_tuple(shadow_ray.origin);
	// print_tuple(shadow_ray.direction);
	xs_list = intersect_world(scene, &shadow_ray);
	the_hit = hit(xs_list);
	free_intersections_list(&xs_list);
	if (the_hit && the_hit->is_hit && the_hit->t < distance)
	{
		free_intersections_list(&the_hit);
		return (true);
	}
	free_intersections_list(&the_hit);
	return (false);
}
