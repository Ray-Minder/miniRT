#include "../../include/minirt.h"

t_x	*intersect(t_ray *ray, t_object *object)
{
	t_ray		transformed_ray;

	if (!ray || !object)
	{
		printf("Returning intersect because there's no ray or object\n");
		return (NULL);
	}
	transformed_ray = transform_ray(ray, object->inverse_transform);
	if (object->type == SPHERE)
		return (sphere_intersect(&transformed_ray, object));
	if (object->type == PLANE)
		return (plane_intersect(&transformed_ray, object));
	// if (object->type == CYLINDER)
	// 	return (cylinder_intersect(&transformed_ray, object));
	printf("Returning intersect because the object type wasn't SPHERE\n");
	return (NULL);
}

t_x	*hit(t_x *xs_list)
{
	t_x	*current;
	t_x	*lowest_hit;

	if (!xs_list)
		return (NULL);
	current = xs_list;
	lowest_hit = NULL;
	while (current != NULL)
	{
		if (current->t > 0 && (!lowest_hit || current->t < lowest_hit->t))
			lowest_hit = current;
		current = current->next;
	}
	// printf("Lowest hit: %f\n", lowest_hit->t);
	return (lowest_hit);
}

void	add_intersection_node(t_x **xs_list, t_x *current)
{
	t_x	*iterator;

	if (!xs_list && !current)
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
	xs->hit = true;
	xs->object = sphere;
	if (xs->next)
	{
		xs->next->hit = true;
		xs->next->object = sphere;
		xs->next->next = NULL;
	}
	// printf("Returned intersection: %f\n", xs->t);
	return (xs);
}

t_x *plane_intersect(t_ray *ray, t_object *plane)
{
	t_x *xs;

	xs = new_intersection_node();
	if (!xs)
		return (NULL);
	// printf("plane intersect();");
	// printf("ray origin:\n");
	// print_tuple(ray->origin);
	// printf("ray direction:\n");
	// print_tuple(ray->direction);
	if (compare_doubles(ray->direction.y, 0.0))
	{
		xs->t = 0;
		return (xs);
	}
	// printf("-ray origin y: %f, ray direction y: %f\n", -ray->origin.y, ray->direction.y);
	xs->t = -ray->origin.y / ray->direction.y;
	xs->hit = true;
	xs->object = plane;
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
