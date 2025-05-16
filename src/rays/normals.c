/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:14:01 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:08 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

t_tuple	normal_at(t_object *object, t_tuple world_point);
t_tuple	normal_at_plane(t_object *object, t_tuple world_point);
t_tuple	normal_at_cylinder(t_object *object, t_tuple world_point);
t_tuple	normal_at_sphere(t_object *object, t_tuple world_point);

//	=== Function Definitions ===

t_tuple	normal_at(t_object *object, t_tuple world_point)
{
	if (object->type == SPHERE)
		return (normal_at_sphere(object, world_point));
	else if (object->type == PLANE)
		return (normal_at_plane(object, world_point));
	else if (object->type == CYLINDER)
		return (normal_at_cylinder(object, world_point));
	else
	{
		ft_putstr_fd("Error: normal_at called on unknown object type\n", 2);
		exit(EXIT_FAILURE);
	}
}

t_tuple	normal_at_plane(t_object *object, t_tuple world_point)
{
	t_tuple	object_normal;

	if (object->type != PLANE)
	{
		ft_putstr_fd("Error: normal_at_plane\n", 2);
		exit(EXIT_FAILURE);
	}
	(void) world_point;
	object_normal = vector(0, 1, 0);
	return (multiply_matrix_by_tuple(object->inv_transpose, object_normal));
}

t_tuple	normal_at_cylinder(t_object *object, t_tuple world_point)
{
	t_tuple	object_normal;
	t_tuple	object_point;
	t_tuple	world_normal;
	double	distance;

	if (object->type != CYLINDER)
	{
		ft_putstr_fd("Error: normal_at_cylinder\n", 2);
		exit(EXIT_FAILURE);
	}
	object_point = multiply_matrix_by_tuple(object->inv_transform,
			world_point);
	object_normal = vector(object_point.x, 0, object_point.z);
	distance = object_point.x * object_point.x + object_point.z
		* object_point.z;
	if (distance < 1.0 && compare_doubles(object_point.y, object->height / 2))
		object_normal = vector(0, 1, 0);
	else if (distance < 1.0 && compare_doubles(object_point.y,
			-object->height / 2))
		object_normal = vector(0, -1, 0);
	world_normal = multiply_matrix_by_tuple(object->inv_transpose,
			object_normal);
	world_normal.w = 0;
	world_normal = normalize_tuple(world_normal);
	return (world_normal);
}

t_tuple	normal_at_sphere(t_object *object, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	if (object->type != SPHERE)
	{
		ft_putstr_fd("Error: normal_at_sphere\n", 2);
		exit(EXIT_FAILURE);
	}
	object_point = multiply_matrix_by_tuple(object->inv_transform,
			world_point);
	object_normal = subtract_tuples(object_point, point(0, 0, 0));
	object_normal.w = 0;
	world_normal = multiply_matrix_by_tuple(object->inv_transpose,
			object_normal);
	world_normal.w = 0;
	return (normalize_tuple(world_normal));
}
