#include "../../include/minirt.h"

t_color shade_hit(t_scene *scene, t_comps *comps)
{
	t_color final_color;

	if (is_shadowed(scene, comps->point))
		final_color = ambient_lighting(scene->ambient_light, comps->object->material.color);
	else
	final_color = lighting(scene, comps);
	return (final_color);
}

bool is_shadowed(t_scene *scene, t_tuple point)
{
	double	distance;
	t_ray	shadow_ray;
	t_x		*xs_list;
	t_x		*_hit;

	distance = tuple_magnitude(subtract_tuples(scene->light.position, point));
	shadow_ray.origin = point;
	shadow_ray.direction = normalize_tuple(subtract_tuples(scene->light.position, point));
	xs_list = intersect_world(scene, &shadow_ray);
	_hit = hit(xs_list);
	free_intersections_list(&xs_list);
	if (_hit && _hit->hit && _hit->t < distance)
		return (true);
	return (false);
}
