#include "../../include/minirt.h"

t_color	lighting(t_scene *scene, t_comps *comps)
{
	t_color	ambient_contribution;
	t_color	diffuse_contribution;
	t_color	specular_contribution;
	double	reflect_dot_eye;
	t_tuple	lightv;					//Vector from point to light
	t_tuple reflectv;

	ambient_contribution = ambient_lighting(scene->ambient_light, comps->object->material.color);
	diffuse_contribution = diffuse_lighting(scene->light, comps->normalv, comps->point, comps->object->material.color);

	lightv = normalize_tuple(subtract_tuples(scene->light.position, comps->point));
	reflectv = reflect(negate_tuple(lightv), comps->normalv);
	reflect_dot_eye = dot_product(comps->eyev, reflectv);
	specular_contribution = specular_lighting(scene->light, comps->object->material, reflect_dot_eye);
	specular_contribution = color(0,0,0);
	
	return (add_colors(ambient_contribution, add_colors(diffuse_contribution, specular_contribution)));
}
