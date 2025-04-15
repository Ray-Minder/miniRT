#include "../../include/minirt.h"

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
	// t_tuple object_normal;

	if (object->type != PLANE)
	{
		ft_putstr_fd("Error: normal_at_plane\n", 2);
		exit(EXIT_FAILURE);
	}
	(void) world_point;
	// object_normal = vector(0, 1, 0);
	// return (multiply_matrix_by_tuple(transpose_matrix(invert_matrix(object->transform)), object_normal));
	return (object->direction);
	// return (object_normal);
}

t_tuple normal_at_cylinder(t_object *object, t_tuple world_point)
{
	t_tuple object_normal;
	t_tuple object_point;

	if (object->type != CYLINDER)
	{
		ft_putstr_fd("Error: normal_at_cylinder\n", 2);
		exit(EXIT_FAILURE);
	}
	object_point = multiply_matrix_by_tuple(invert_matrix(object->transform), world_point);
	object_normal = vector(object_point.x, 0, object_point.z);
	return (multiply_matrix_by_tuple(transpose_matrix(invert_matrix(object->transform)), object_normal));
}

t_tuple normal_at_sphere(t_object *object, t_tuple world_point)
{
	t_tuple object_point;
	t_tuple object_normal;
	t_tuple world_normal;

	if (object->type != SPHERE)
	{
		ft_putstr_fd("Error: normal_at_sphere\n", 2);
		exit(EXIT_FAILURE);
	}
	object_point = multiply_matrix_by_tuple(object->inverse_transform, world_point);
	// object_point = multiply_matrix_by_tuple(invert_matrix(identity(4)), world_point);
	// object_normal = subtract_tuples(object_point, object->position);
	object_normal = subtract_tuples(object_point, point(0, 0, 0));
	object_normal.w = 0;
	world_normal = multiply_matrix_by_tuple(transpose_matrix(object->inverse_transform), object_normal);
	world_normal.w = 0;
	world_normal = subtract_tuples(world_point, object->position);
	return (normalize_tuple(world_normal));
}

t_tuple reflect(t_tuple in, t_tuple normal)
{
	t_tuple reflected;

	reflected = subtract_tuples(in, multiply_tuple_by_scalar(normal, 2 * dot_product(in, normal)));
	return (reflected);
}
