#include "../../include/intersect.h"
#include "math.h"

t_xs	*intersect(t_ray *ray, t_object *object)
{
	if (!ray || !object)
		return (NULL);
	if (object->type == SPHERE)
		return (sphere_intersect(ray, object));
	return (NULL);
}

void	add_intersection(t_xs **xs_list, t_xs *current)
{
	t_xs	*iterator;

	if ((!xs_list || !*xs_list) && !current)
	{
		printf("There's no xs list, and no intersection to add either.\n");
		return ;
	}
	if (xs_list && !*xs_list && current)
	{
		*xs_list = current;
		return ;
	}
	iterator = *xs_list;
	while (iterator && iterator->next)
		iterator = iterator->next;
	iterator->next = current;
}

t_xs	*sphere_intersect(t_ray *ray, t_object *sphere)
{
	t_xs	*xs;
	double	discriminant;
	double	a;
	double	b;
	t_tuple	sphere_to_ray;

	xs = new_intersection_node();
	if (!xs)
		return (NULL);
	discriminant = calculate_discriminant(ray);
	if (discriminant < 0)
	{
		xs->count = 0;
		xs->t[0] = 0;
		xs->t[1] = 0;
		return (xs);
	}
	sphere_to_ray = subtract_tuples(ray->origin, sphere->position);
	a = dot_product(ray->direction, ray->direction);
	b = 2 * dot_product(ray->direction, sphere_to_ray);	
	xs->count = 2;
	xs->t[0] = (-b - sqrt(discriminant)) / (2 * a);
	xs->t[1] = (-b + sqrt(discriminant)) / (2 * a);
	return (xs);
}

double	calculate_discriminant(t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_tuple	sphere_to_ray;
	
	sphere_to_ray = subtract_tuples(ray->origin, point(0, 0, 0));
	a = dot_product(ray->direction, ray->direction);
	b = 2 * dot_product(ray->direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = b * b - 4 * a * c;

	return (discriminant);
}
