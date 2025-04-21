#include "../../include/minirt.h"

//	=== Function Declarations ===

t_tuple		get_right(t_tuple up);
t_matrix	*tuples_to_matrix(t_tuple up, t_tuple right, t_tuple forward, t_tuple position);
t_matrix	*get_transform(t_tuple tuple, t_tuple position);


//	=== Function Definitions ===

t_tuple get_right(t_tuple up)
{
	t_tuple right = cross_product(up, vector(0, 0, 1));
	if (compare_doubles(right.x, 0) && compare_doubles(right.y, 0) && compare_doubles(right.z, 0))
		right = cross_product(up, vector(0, 1, 0));
	return (right);
}

t_matrix *tuples_to_matrix(t_tuple up, t_tuple right, t_tuple forward, t_tuple position)
{
	t_matrix *orientation_matrix;
	t_matrix *inverted_orientation;
	t_matrix *translation_matrix;
	t_matrix *transform_matrix;

	orientation_matrix = identity(4);
	if (!orientation_matrix)
		return (NULL);
	orientation_matrix->values[0][0] = right.x;
	orientation_matrix->values[0][1] = right.y;
	orientation_matrix->values[0][2] = right.z;
	orientation_matrix->values[1][0] = up.x;
	orientation_matrix->values[1][1] = up.y;
	orientation_matrix->values[1][2] = up.z;
	orientation_matrix->values[2][0] = forward.x;
	orientation_matrix->values[2][1] = forward.y;
	orientation_matrix->values[2][2] = forward.z;
	translation_matrix = translation(position.x, position.y, position.z);
	inverted_orientation = invert_matrix(orientation_matrix);
	transform_matrix = multiply_matrices(translation_matrix, inverted_orientation);
	free_matrix(&orientation_matrix);
	free_matrix(&translation_matrix);
	free_matrix(&inverted_orientation);
	return (transform_matrix);
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
