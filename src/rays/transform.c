#include "../../include/rays.h"

t_ray	transform(t_ray *ray, t_matrix *matrix)
{
	t_ray	transformed_ray;

	transformed_ray.origin = multiply_matrix_by_tuple(matrix, ray->origin);
	transformed_ray.direction = multiply_matrix_by_tuple(matrix, ray->direction);
	return (transformed_ray);
}
