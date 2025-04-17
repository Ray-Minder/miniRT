#include "../../include/minirt.h"

t_color	lighting(t_scene *scene, t_comps *comps)
{
	t_color	ambient_contribution;
	t_color	diffuse_contribution;

	ambient_contribution = ambient_lighting(scene->ambient_light, comps->object->color);
	diffuse_contribution = diffuse_lighting(scene->light, comps->normalv, comps->point, comps->object->color);
	return (add_colors(ambient_contribution, diffuse_contribution));
}
