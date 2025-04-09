#include "../../include/minirt.h"

t_color color_at(t_scene *scene, t_ray *ray)
{
	t_comps		*comps;
	t_color		final_color;
	t_x			*xs_list;
	t_x			*_hit;

	xs_list = intersect_world(scene, ray);
	_hit = hit(xs_list);
	if (_hit && _hit->hit)
	{
		comps = prepare_computations(_hit, ray);
		free_intersections_list(&xs_list);
	}
	else
	{
		free_intersections_list(&xs_list);
		return (scene->ambient_light.color);
	}
	// final_color = lighting(scene, comps); // Replace by shade_hit
	final_color = shade_hit(scene, comps);
	ft_free((void **) &comps);
	// free_intersections_list(&_hit);
	return (final_color);
}
