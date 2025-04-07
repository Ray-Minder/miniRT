#include "../../include/minirt.h"

// t_color shade_hit(t_scene *scene, t_comps *comps)
// {
// 	t_color final_color;

// 	if (is_in_shadow(scene, comps->point))
// 		final_color = apply_shadow(lighting(scene, comps));
// 	else
// 		final_color = lighting(scene, comps);

// 	return (final_color);
// }

// t_color apply_shadow(t_color color)
// {
// 	t_color shadow_color;

// 	shadow_color.r = color.r * 0.5;
// 	shadow_color.g = color.g * 0.5;
// 	shadow_color.b = color.b * 0.5;

// 	return (shadow_color);
// }

// bool is_in_shadow(t_scene *scene, t_tuple point)
// {
// 	t_ray	shadow_ray;
// 	t_x		*xs_list;
// 	t_x		*hit;

// 	shadow_ray.origin = point;
// 	shadow_ray.direction = normalize_tuple(subtract_tuples(scene->light.position, point));
// 	xs_list = intersect_world(scene, &shadow_ray);
// 	hit = hit(xs_list);
// 	free_intersections_list(&xs_list);

// 	if (hit && hit->hit)
// 		return (true);
// 	return (false);
// }
