#include "../../include/minirt.h"

t_x	*sphere_intersect(t_ray *ray, t_object *sphere)
{
	t_x		*xs;
	double	discriminant;
	double	a;
	double	b;
	t_tuple	sphere_to_ray;

	xs = new_intersection_node();
	if (!xs)
	{
		printf("failure to allocate new intersection\n");
		return (NULL);
	}
	discriminant = calculate_discriminant(ray);
	if (discriminant < 0)
	{
		// printf("There's no intersection because discriminant is less than 0\n");
		xs->t = 0;
		return (xs);
	}
	xs->next = new_intersection_node();
	if (!xs->next)
		return (free_intersections_list(&xs), NULL);
	sphere_to_ray = subtract_tuples(ray->origin, sphere->position);
	a = dot_product(ray->direction, ray->direction);
	b = 2 * dot_product(ray->direction, sphere_to_ray);
	xs->t = (-b - sqrt(discriminant)) / (2 * a);
	xs->next->t = (-b + sqrt(discriminant)) / (2 * a);
	xs->is_hit = true;
	if (xs->next)
		xs->next->is_hit = true;
	// printf("Returned intersection: %f\n", xs->t);
	return (xs);
}
