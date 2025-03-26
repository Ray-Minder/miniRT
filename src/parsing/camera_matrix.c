#include "../../include/scene.h"
#include "../../include/parser.h"

t_tuple get_camera_right(t_tuple forward)
{
	t_tuple right = cross_product(forward, vector(0, 1, 0));
	if (compare_doubles(right.x, 0) && compare_doubles(right.y, 0) && compare_doubles(right.z, 0))
		right = cross_product(forward, vector(0, 0, 1));
	return (right);
}

t_matrix *get_camera_matrix(t_camera camera)
{
	t_tuple forward;
	t_tuple	up;
	t_tuple right;
	t_matrix *transform;

	forward = normalize_tuple(camera.forward);
	right = get_camera_right(forward);
	right = normalize_tuple(right);
	up = cross_product(right, forward);
	up = normalize_tuple(up);	
	transform = tuples_to_matrix(up, right, forward, camera.position);
	return (transform);
}

t_matrix *get_light_matrix(t_light light)
{
	t_tuple right;
	t_tuple forward;
	t_tuple up;
	t_matrix *transform;

	right = normalize_tuple(vector(1, 0, 0));
	forward = normalize_tuple(vector(0, 0, 1));
	up = normalize_tuple(vector(0, 1, 0));
	transform = tuples_to_matrix(up, right, forward, light.position);
	return (transform);
}

int set_transforms(t_scene *scene)
{
	if (set_object_transforms(scene->objects) != SUCCESS)
		return (MALLOC_FAIL);
	scene->camera.transform = get_camera_matrix(scene->camera);
	if (!scene->camera.transform)
		return (MALLOC_FAIL);
	scene->light.transform = get_light_matrix(scene->light);
	if (!scene->light.transform)	
		return (MALLOC_FAIL);
	return (SUCCESS);
}