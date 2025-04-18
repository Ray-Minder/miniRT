#include "../../include/minirt.h"

t_x *create_node_pair(t_object *cylinder)
{
	t_x	*xs;

	xs = new_intersection_node();
	if (xs == NULL)
		return (NULL);
	xs->object = cylinder;
	xs->next = new_intersection_node();
	if (xs->next == NULL)
	{
		free_intersection_node(&xs);
		return (NULL);
	}
	xs->next->object = cylinder;
	return (xs);
}

bool check_cap(t_ray *ray, double t)
{
	double x;
	double z;

	x = ray->origin.x + t * ray->direction.x;
	z = ray->origin.z + t * ray->direction.z;
	if (x * x + z * z <= 1.0)
		return (true);
	return (false);
}

t_x *intersect_caps(t_object *cylinder, t_ray *ray)
{
	double t0;
	double t1;
	t_x *caps;

	caps = create_node_pair(cylinder);
	if (caps == NULL)
		return (NULL);
	if (compare_doubles(ray->direction.y, 0.0))
	{
		return (NULL);
	}
	t0 = (0 - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, t0))
	{
		printf("t0: %f\n", t0);
		caps->t = t0;
		caps->hit = true;
	}
	t1 = (cylinder->height - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, t1))
	{
		printf("t1: %f\n", t1);
		caps->next->t = t1;
		caps->next->hit = true;
	}
	return (caps);
}

t_x *cylinder_intersect(t_ray *ray, t_object *cylinder)
{
	t_x		*xs;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	xs = create_node_pair(cylinder);
	if (xs == NULL)
		return (NULL);
	a = ray->direction.x * ray->direction.x + ray->direction.z * ray->direction.z;
	if (compare_doubles(a, 0.0))
	{
		return (xs);
	}
	b = 2 * (ray->origin.x * ray->direction.x) + 2 * (ray->origin.z * ray->direction.z);
	c = ray->origin.x * ray->origin.x + ray->origin.z * ray->origin.z - 1.0;
	discriminant = b * b - 4 * a * c;
	
	// printf("a: %f, b: %f, c: %f, discriminant: %f\n", a, b, c, discriminant);
	if (discriminant < 0)
	{
		return (xs);
	}
	xs->t = (-b - sqrt(discriminant)) / (2 * a);
	xs->next->t = (-b + sqrt(discriminant)) / (2 * a);
	xs->hit = true;
	xs->next->hit = true;
	if (xs->t > xs->next->t)
	{
		double temp = xs->t;
		xs->t = xs->next->t;
		xs->next->t = temp;
	}
	double y0 = ray->origin.y + xs->t * ray->direction.y;
	double y1 = ray->origin.y + xs->next->t * ray->direction.y;
	if ((0) < y0 && y0 < (cylinder->height * 2))
	{
		xs->hit = true;
	}
	else
	{
		xs->t = 0;
		xs->hit = false;
	}
	if ((0) < y1 && y1 < (cylinder->height * 2))
	{
		xs->next->hit = true;
	}
	else
	{
		xs->next->t = 0;
		xs->next->hit = false;
	}
	add_intersection_node(&xs, intersect_caps(cylinder, ray));
	// print_intersection_list(xs);
	return (xs);
}