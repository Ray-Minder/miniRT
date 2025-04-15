#include "../../include/minirt.h"

t_color shade_hit(t_scene *scene, t_comps *comps)
{
	t_color final_color;

	// if (is_shadowed(scene, comps->over_point))
	// {
	// 	final_color = ambient_lighting(scene->ambient_light, comps->object->color);
	// }
	// else
		final_color = lighting(scene, comps);
	return (final_color);
}

bool is_shadowed(t_scene *scene, t_tuple over_point)
{
	t_tuple	light_vector;
	double	distance;
	t_ray	shadow_ray;
	t_x		*xs_list;
	t_x		*_hit;

	light_vector = subtract_tuples(scene->light.position, over_point);
	distance = tuple_magnitude(light_vector);
	shadow_ray.origin = over_point;
	shadow_ray.direction = normalize_tuple(light_vector);
	xs_list = intersect_world(scene, &shadow_ray);
	_hit = hit(xs_list);
	free_intersections_list(&xs_list);
	if (_hit && _hit->hit && _hit->t < distance)
	{
		free_intersections_list(&_hit);
		return (true);
	}
	free_intersections_list(&_hit);
	return (false);
}
