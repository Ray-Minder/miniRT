#include "../../include/minirt.h"

//	=== Function Declarations ===

t_tuple		get_right(t_tuple up);
t_matrix	*tuples_to_matrix(	t_tuple up,
				t_tuple right,
				t_tuple forward,
				t_tuple position);
t_matrix	*get_transform(t_tuple tuple, t_tuple position);

//	=== Function Definitions ===

t_tuple	get_right(t_tuple up)
{
	t_tuple	right;

	right = cross_product(up, vector(0, 0, 1));
	if (compare_doubles(tuple_magnitude(right), 0.0))
		right = cross_product(up, vector(0, 1, 0));
	return (right);
}

t_matrix	*tuples_to_matrix(
	t_tuple up,
	t_tuple right,
	t_tuple forward,
	t_tuple position)
{
	t_matrix	*orientate;
	t_matrix	*inv_orientate;
	t_matrix	*translate;
	t_matrix	*transform;

	orientate = identity(4);
	if (!orientate)
		return (NULL);
	orientate->values[0][0] = right.x;
	orientate->values[0][1] = right.y;
	orientate->values[0][2] = right.z;
	orientate->values[1][0] = up.x;
	orientate->values[1][1] = up.y;
	orientate->values[1][2] = up.z;
	orientate->values[2][0] = forward.x;
	orientate->values[2][1] = forward.y;
	orientate->values[2][2] = forward.z;
	translate = translation(position.x, position.y, position.z);
	inv_orientate = invert_matrix(orientate);
	transform = multiply_matrices(translate, inv_orientate);
	free_matrix(&orientate);
	free_matrix(&translate);
	free_matrix(&inv_orientate);
	return (transform);
}

t_matrix	*get_transform(t_tuple tuple, t_tuple position)
{
	t_tuple		forward;
	t_tuple		right;
	t_matrix	*transform;

	tuple = normalize_tuple(tuple);
	right = get_right(tuple);
	right = normalize_tuple(right);
	forward = cross_product(right, tuple);
	forward = normalize_tuple(forward);
	transform = tuples_to_matrix(tuple, right, forward, position);
	return (transform);
}
