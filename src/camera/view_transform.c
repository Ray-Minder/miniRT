#include "../../include/minirt.h"

//	=== Function Declarations ===

t_matrix	*view_transform(t_tuple forward, t_tuple point);
static void	set_orientation_values(t_matrix *orientation, t_tuple right,
				t_tuple up, t_tuple forward);

//	=== Function Definitions ===

/**
 * @brief This function computes the camera's view matrix.
 * 
 * @param forward The forward vector of the camera.
 * @param point The point in world space where the camera is looking.
 * @return A pointer to a matrix representing the view transformation.
 * 
 * @note This function computes a view matrix by deriving right and up vectors
 * from the given forward vector.
 * It constructs a transformation matrix that orients and positions the camera
 * in world space.
 * The resulting matrix, combining rotation and translation,
 * transforms points from world space to camera space.
 */
t_matrix	*view_transform(t_tuple forward, t_tuple point)
{
	t_tuple		right;
	t_tuple		up;
	t_matrix	*orientation;
	t_matrix	*translation_m;
	t_matrix	*_view_transform;

	right = normalize_tuple(get_camera_right(forward));
	up = cross_product(right, forward);
	orientation = identity(4);
	if (!orientation)
		return (NULL);
	set_orientation_values(orientation, right, up, forward);
	translation_m = translation(-point.x, -point.y, -point.z);
	if (!translation_m)
	{
		free_matrix(&orientation);
		return (NULL);
	}
	_view_transform = multiply_matrices(orientation, translation_m);
	free_matrix(&orientation);
	free_matrix(&translation_m);
	if (!_view_transform)
		return (NULL);
	return (_view_transform);
}

static void	set_orientation_values(t_matrix *orientation, t_tuple right,
	t_tuple up, t_tuple forward)
{
	orientation->values[0][0] = right.x;
	orientation->values[0][1] = right.y;
	orientation->values[0][2] = right.z;
	orientation->values[1][0] = up.x;
	orientation->values[1][1] = up.y;
	orientation->values[1][2] = up.z;
	orientation->values[2][0] = -forward.x;
	orientation->values[2][1] = -forward.y;
	orientation->values[2][2] = -forward.z;
}
