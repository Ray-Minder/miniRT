#include "../../include/minirt.h"

t_color shade_hit(t_data *data, t_comps *comps)
{
	t_color final_color;
	t_scene	*scene;

	scene = data->scene;
	if (is_shadowed(data, comps->over_point))
	{
		final_color = ambient_lighting(scene->ambient_light, comps->object->color);
	}
	else
		final_color = lighting(scene, comps);
	return (final_color);
}

bool is_shadowed(t_data *data, t_tuple over_point)
{
	t_tuple	light_vector;
	double	distance;
	t_ray	shadow_ray;
	t_x		*xs_list;
	t_x		*the_hit;

	light_vector = subtract_tuples(data->scene->light.position, over_point);
	distance = tuple_magnitude(light_vector);
	shadow_ray.origin = over_point;
	shadow_ray.direction = normalize_tuple(light_vector);
	xs_list = intersect_world(data, &shadow_ray);
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
