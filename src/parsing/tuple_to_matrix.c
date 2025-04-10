#include "../../include/minirt.h"
#include "../../include/parser.h"

t_tuple get_right(t_tuple up)
{
	t_tuple right = cross_product(up, vector(0, 0, 1));
	if (compare_doubles(right.x, 0) && compare_doubles(right.y, 0) && compare_doubles(right.z, 0))
		right = cross_product(up, vector(0, 1, 0));
	return (right);
}

t_matrix *tuples_to_matrix(t_tuple up, t_tuple right, t_tuple forward, t_tuple position)
{
	t_matrix *matrix;
	double	data[16];

	data[0] = right.x;
	data[1] = right.y;
	data[2] = right.z;
	data[3] = right.w;
	data[4] = up.x;
	data[5] = up.y;
	data[6] = up.z;
	data[7] = up.w;
	data[8] = forward.x;
	data[9] = forward.y;
	data[10] = forward.z;
	data[11] = forward.w;
	data[12] = position.x;
	data[13] = position.y;
	data[14] = position.z;
	data[15] = position.w;
	matrix = create_matrix(4, 4);
	if (!matrix)
		return (NULL);
	initialize_matrix(matrix, data, 16);
	return (matrix);
}

t_matrix *get_transform(t_tuple tuple, t_tuple position)
{
	t_tuple forward;
	t_tuple right;
	t_matrix *transform;

	tuple = normalize_tuple(tuple);
	right = get_right(tuple);
	right = normalize_tuple(right);
	forward = cross_product(right, tuple);
	forward = normalize_tuple(forward);
	transform = tuples_to_matrix(tuple, right, forward, position);
	return (transform);
}

int set_object_transforms(t_object *objects)
{
	t_matrix	*translate;
	t_matrix	*scaled;

	while (objects)
	{
		if (objects->type == SPHERE)
			objects->direction = vector(0, 1, 0);
		objects->transform = identity(4);
		if (!objects->transform)
			return (MALLOC_FAIL);
		translate = translate_from_tuple(objects->position);
		if (!translate)
			return (MALLOC_FAIL);
		scaled = scaling(objects->diameter / 2, objects->diameter / 2, objects->diameter / 2);
		if (!scaled)
			return (MALLOC_FAIL);
		objects->transform = multiply_matrices(translate, scaled);
		// objects->transform = scaling(objects->diameter / 2, objects->diameter / 2, objects->diameter / 2);
		if (!objects->transform)
			return (MALLOC_FAIL);
		// objects->inverse_transform = invert_matrix(objects->transform);
		// if (!objects->inverse_transform)
		// 	return (MALLOC_FAIL);
		objects = objects->next;
	}
	return (SUCCESS);
}
