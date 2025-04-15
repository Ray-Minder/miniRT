#include "../../include/minirt.h"

t_color	lighting(t_scene *scene, t_comps *comps)
{
	t_color	ambient_contribution;
	t_color	diffuse_contribution;

	// printf("--- Lighting Debug ---\n");
	// printf("Light Pos: ");
	// print_tuple(scene->light.position);
	// printf("Hit Point: ");
	// print_tuple(comps->point);
	// printf("Normal Vec: ");
	// print_tuple(comps->normalv);
	// t_tuple expected_light_dir = normalize_tuple(subtract_tuples(scene->light.position, comps->point));
	// printf("Expected Light Dir: ");
	// print_tuple(expected_light_dir);
	// printf("Dot Prod (N . L): %f\n", dot_product(comps->normalv, expected_light_dir));
	// printf("----------------------\n");

	ambient_contribution = ambient_lighting(scene->ambient_light, comps->object->color);
	diffuse_contribution = diffuse_lighting(scene->light, comps->normalv, comps->point, comps->object->color);
	return (add_colors(ambient_contribution, diffuse_contribution));
}
