#include "../../include/minirt.h"

/**
 * @brief Computes the color at a given point in the scene based on the ray.
 * 
 * @param scene Pointer to the scene structure.
 * @param ray Pointer to the ray structure.
 * @return A t_color structure representing the color at the intersection point.
 * 
 * This function first checks for intersections between the ray and the objects in the scene.
 * If an intersection is found, it prepares the computations for shading.
 * It then calculates the color at the intersection point using the shading function.
 * If no intersection is found, it returns the ambient light color.
 * The function also handles memory management for the intersection list and computations.
 */
t_color color_at(t_scene *scene, t_ray *ray)
{
	t_comps		*comps;
	t_color		final_color;
	t_x			*xs_list;
	t_x			*_hit;

	xs_list = intersect_world(scene, ray);
	_hit = hit(xs_list); // Add prepare computations within this function?
	free_intersections_list(&xs_list);
	if (_hit && _hit->hit)
		comps = prepare_computations(_hit, ray);
	else
		return (scene->ambient_light.color); //Is this right though? Or maybe a black background that intersects with ambient light?
	final_color = shade_hit(scene, comps);
	ft_free((void **) &comps);
	free_intersections_list(&_hit); // Sometimes we get a double free because the hit list takes nodes from the intersect list.
	return (final_color);
}
