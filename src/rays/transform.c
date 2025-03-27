#include "../../include/rays.h"

t_ray	transform(t_ray *ray, t_matrix *matrix)
{
	t_ray	transformed_ray;

	transformed_ray.origin = multiply_matrix_by_tuple(matrix, ray->origin);
	transformed_ray.direction = multiply_matrix_by_tuple(matrix, ray->direction);
	return (transformed_ray);
}

void	set_transform(t_object *object, t_matrix *transformation)
{
	t_matrix	*chained_transform;
	t_matrix	*array_of_transformations[3];

	// printf("In set transform\n");
	array_of_transformations[0] = object->transform;
	array_of_transformations[1] = transformation;
	array_of_transformations[2] = NULL;
	chained_transform = chain_transformations(array_of_transformations);
	// printf("Chained transformation: \n");
	// print_matrix(chained_transform);
	if (!chained_transform)
	{
		printf("Error at setting a transformation.\n");
		return ;
	}
	free_matrix(&object->transform);
	object->transform = chained_transform;
	return ;
}
