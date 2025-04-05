#include "../../include/minirt.h"

t_x	*intersect(t_ray *ray, t_object *object)
{
	t_ray	transformed_ray;

	if (!ray || !object)
	{
		printf("Returning intersect because there's no ray or object\n");
		return (NULL);
	}
	if (!object->transform)
		object->transform = identity(4); //LATER REMOVE, IT SHOULD be INIT already. 
	transformed_ray = transform(ray, invert_matrix(object->transform));
	if (object->type == SPHERE)
		return (sphere_intersect(&transformed_ray, object));
	printf("Returning intersect because the object type wasn't SPHERE\n");
	return (NULL);
}

t_x	*hit(t_x *xs_list)
{
	t_x	*current;
	t_x	*lowest_hit;

	if (!xs_list)
	{
		printf("Cannot determine the hit from a NULL xs_list.\n");
		return (NULL);
	}
	current = xs_list;
	lowest_hit = current;
	while (current != NULL)
	{
		if (current->t > 0 && current->t < lowest_hit->t)
			lowest_hit = current;
		current = current->next;
	}
	// printf("Lowest hit: %f\n", lowest_hit->t);
	return (lowest_hit);
}

void	add_intersection_node(t_x **xs_list, t_x *current)
{
	t_x	*iterator;

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
