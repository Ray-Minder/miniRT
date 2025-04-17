#include "../../include/minirt.h"
#include "../../include/parser.h"

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
t_tuple get_camera_right(t_tuple forward)
{
	t_tuple right;
	
	right = cross_product(forward, vector(0, 1, 0));
	if (is_zero_vector(right))
		right = cross_product(forward, vector(0, 0, 1));
	return (right);
}

//USING VIEW_TRANSFORM INSTEAD
// t_matrix *get_camera_matrix(t_camera camera)
// {
// 	t_tuple forward;
// 	t_tuple	up;
// 	t_tuple right;
// 	t_matrix *transform;

// 	forward = normalize_tuple(camera.forward);
// 	right = get_camera_right(forward);
// 	right = normalize_tuple(right);
// 	up = cross_product(right, forward);
// 	up = normalize_tuple(up);	
// 	transform = tuples_to_matrix(up, right, forward, camera.position);
// 	if (!transform)
// 	{
// 		print_error_msg("There was an error creating the camera matrix.\n");
// 		return (NULL);
// 	}
// 	return (transform);
// }

// t_matrix *get_light_matrix(t_light light)
// {
// 	t_tuple right;
// 	t_tuple forward;
// 	t_tuple up;
// 	t_matrix *transform;
// 	t_matrix *translated;

// 	right = normalize_tuple(vector(1, 0, 0));
// 	forward = normalize_tuple(vector(0, 0, 1));
// 	up = normalize_tuple(vector(0, 1, 0));
// 	transform = tuples_to_matrix(up, right, forward, light.position);
// 	// transform = identity(4);
// 	if (!transform)
// 	{
// 		print_error_msg("There was an error creating the light matrix.\n");
// 		return (NULL);
// 	}
// 	translated = translate_from_tuple(light.position);
// 	if (!translated)
// 	{
// 		print_error_msg("There was an error creating the light matrix.\n");
// 		return (NULL);
// 	}
// 	return (transform);
// }

int set_transforms(t_scene *scene)
{
	if (set_object_transforms(scene->objects) != SUCCESS)
		return (MALLOC_FAIL);
	// scene->camera.transform = get_camera_matrix(scene->camera);
	scene->camera.transform = view_transform(scene->camera.forward, scene->camera.position);
	if (!scene->camera.transform)
		return (MALLOC_FAIL);
	// scene->light.transform = translate_from_tuple(scene->light.position);
	scene->light.transform = NULL;
	// if (!scene->light.transform)	
	// 	return (MALLOC_FAIL);
	return (SUCCESS);
}
