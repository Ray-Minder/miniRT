#include "../../include/minirt.h"

t_matrix	*view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	*orientation;
	t_matrix	*_view_transform;

	forward = normalize_tuple(subtract_tuples(to, from));
	left = normalize_tuple(cross_product(forward, up));
	true_up = cross_product(left, forward);
	orientation = identity(4);
	if (!orientation)
		return (NULL);
	orientation->values[0][0] = left.x;
	orientation->values[0][1] = left.y;
	orientation->values[0][2] = left.z;
	orientation->values[1][0] = true_up.x;
	orientation->values[1][1] = true_up.y;
	orientation->values[1][2] = true_up.z;
	orientation->values[2][0] = -forward.x;
	orientation->values[2][1] = -forward.y;
	orientation->values[2][2] = -forward.z;
	_view_transform = multiply_matrices(orientation, translation(-from.x, -from.y, -from.z));
	free_matrix(&orientation);
	return (_view_transform);
}
