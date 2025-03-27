#include "../../include/normals.h"
#include "../../include/scene.h"
#include "../../include/tuples.h"

t_tuple normal_at_sphere(t_object *object, t_tuple world_point)
{
	t_tuple object_point;
	t_tuple object_normal;
	// t_tuple world_point;
	t_tuple world_normal;

	if (object->type != SPHERE)
	{
		ft_putstr_fd("Error: normal_at_sphere() called on non-sphere object\n", 2);
		exit(EXIT_FAILURE);
	}
	object_point = multiply_matrix_by_tuple(invert_matrix(object->transform), world_point);
	object_normal = subtract_tuples(object_point, point(0, 0, 0));
	world_normal = multiply_matrix_by_tuple(transpose_matrix(invert_matrix(object->transform)), object_normal);
	world_normal.w = 0;
	return (normalize_tuple(world_normal));
}

t_tuple reflect(t_tuple in, t_tuple normal)
{
	t_tuple reflected;

	reflected = subtract_tuples(in, multiply_tuple_by_scalar(normal, 2 * dot_product(in, normal)));
	return (reflected);
}
