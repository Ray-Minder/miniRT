/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:14:13 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:14:14 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

t_ray	transform_ray(t_data *data, t_ray *ray, t_matrix *matrix);
void	set_transform(t_object *object, t_matrix *transformation);

//	=== Function Definitions ===

t_ray	transform_ray(t_data *data, t_ray *ray, t_matrix *matrix)
{
	t_ray	transformed_ray;

	if (!ray || !is_matrix_initialized(matrix) || matrix->rows != 4)
	{
		print_clean_and_exit(data, INVALID_ELEMENT, EXIT_FAILURE);
	}
	transformed_ray.origin = multiply_matrix_by_tuple(matrix, ray->origin);
	transformed_ray.dir = multiply_matrix_by_tuple(matrix,
			ray->dir);
	return (transformed_ray);
}

void	set_transform(t_object *object, t_matrix *transformation)
{
	t_matrix	*chained_transform;
	t_matrix	*array_of_transformations[3];

	array_of_transformations[0] = object->transform;
	array_of_transformations[1] = transformation;
	array_of_transformations[2] = NULL;
	chained_transform = chain_transformations(array_of_transformations);
	if (!chained_transform)
	{
		printf("Error at setting a transformation.\n");
		return ;
	}
	free_matrix(&object->transform);
	object->transform = chained_transform;
	return ;
}
