#include "../../include/rays.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	return (add_tuples(ray.origin, multiply_tuple_by_scalar(ray.direction, t)));
}
