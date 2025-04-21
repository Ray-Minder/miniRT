#include "../../include/minirt.h"

//	=== Function Declarations ===

t_tuple	get_camera_right(t_tuple forward);
int		set_transforms(t_scene *scene);

//	=== Function Definitions ===

/**
 * @brief Computes the right vector for the camera based on the forward vector.
 * 
 * @param forward The forward vector of the camera.
 * @return The right vector of the camera.
 * 
 * @note This function calculates the right vector by taking the cross product
 * of the forward vector and the up vector (0, 1, 0).
 * If the result is a zero vector, it uses the cross product
 * of the forward vector and (0, 0, 1) instead.
 * This ensures that the right vector is always perpendicular
 * to the forward vector.
 * 
 * It returns a NOT NORMALIZED vector.
 */
t_tuple	get_camera_right(t_tuple forward)
{
	t_tuple right;
	
	right = cross_product(forward, vector(0, 1, 0));
	if (is_zero_vector(right))
		right = cross_product(forward, vector(0, 0, 1));
	return (right);
}

int	set_transforms(t_scene *scene)
{
	if (set_object_transforms(scene->objects) != SUCCESS)
		return (MALLOC_FAIL);
	scene->camera.transform = view_transform(scene->camera.forward, scene->camera.position);
	if (!scene->camera.transform)
		return (MALLOC_FAIL);
	return (SUCCESS);
}
