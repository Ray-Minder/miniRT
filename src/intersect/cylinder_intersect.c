#include "../../include/minirt.h"

//	=== Function Declarations ===

bool	check_cap(t_ray *ray, double t);
t_x		*intersect_caps(t_object *cylinder, t_ray *ray);
t_x		*cylinder_intersect(t_ray *ray, t_object *cylinder);

//	=== Function Definitions ===

static void	calculate_cylinder_intersection(t_ray *ray, t_x *xs)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	b = 2 * (ray->origin.x * ray->dir.x) + 2 * (ray->origin.z * ray->dir.z);
	c = ray->origin.x * ray->origin.x + ray->origin.z * ray->origin.z - 1.0;
	discriminant = b * b - 4 * a * c;
	if (compare_doubles(a, 0.0) || discriminant < 0)
		return ;
	xs->t = (-b - sqrt(discriminant)) / (2 * a);
	xs->is_hit = true;
	xs->next->t = (-b + sqrt(discriminant)) / (2 * a);
	xs->next->is_hit = true;
}

static void	compare_and_swap_nodes(t_x *xs)
{
	double	temp;

	if (xs->t > xs->next->t)
	{
		temp = xs->t;
		xs->t = xs->next->t;
		xs->next->t = temp;
	}
}

static void	check_cylinder_bounds(t_x *xs, t_ray *ray, double height)
{
	double	y0;
	double	y1;

	y0 = ray->origin.y + xs->t * ray->dir.y;
	y1 = ray->origin.y + xs->next->t * ray->dir.y;
	if (y0 < 0 || y0 > height)
	{
		xs->is_hit = false;
		xs->t = 0;
	}
	if (y1 < 0 || y1 > height)
	{
		xs->next->is_hit = false;
		xs->next->t = 0;
	}
}

t_x	*cylinder_intersect(t_ray *ray, t_object *cylinder)
{
	t_x		*xs;

	xs = create_node_pair(cylinder);
	if (xs == NULL)
		return (NULL);
	calculate_cylinder_intersection(ray, xs);
	compare_and_swap_nodes(xs);
	check_cylinder_bounds(xs, ray, cylinder->height);
	add_intersection_node(&xs, intersect_caps(cylinder, ray));
	return (xs);
}
