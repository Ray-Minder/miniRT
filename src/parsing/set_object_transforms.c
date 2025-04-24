#include "../../include/minirt.h"

//	=== Function Declarations ===

int	set_object_transforms(t_object *objects);
int	set_sphere_transform(t_object *sphere);
int	set_plane_transform(t_object *plane);
int	set_cylinder_transform(t_object *cylinder);

//	=== Function Definitions ===

int	set_object_transforms(t_object *objects)
{
	while (objects)
	{
		if (objects->type == SPHERE)
			set_sphere_transform(objects);
		else if (objects->type == PLANE)
			set_plane_transform(objects);
		else if (objects->type == CYLINDER)
			set_cylinder_transform(objects);
		if (!objects->transform)
			return (MALLOC_FAIL);
		objects->inverse_transform = invert_matrix(objects->transform);
		if (!objects->inverse_transform)
			return (MALLOC_FAIL);
		objects->inverse_transpose = transpose_matrix(objects->inverse_transform);
		if (!objects->inverse_transpose)
			return (MALLOC_FAIL);
		objects = objects->next;
	}
	return (SUCCESS);
}

int	set_sphere_transform(t_object *sphere)
{
	t_matrix	*translate_matrix;
	t_matrix	*scaled_matrix;

	translate_matrix = translate_from_tuple(sphere->position);
	if (!translate_matrix)
		return (MALLOC_FAIL);
	scaled_matrix = scaling(sphere->diameter / 2, sphere->diameter / 2, sphere->diameter / 2);
	if (!scaled_matrix)
		return (MALLOC_FAIL);
	sphere->transform = multiply_matrices(translate_matrix, scaled_matrix);
	free_matrix(&translate_matrix);
	free_matrix(&scaled_matrix);
	if (!sphere->transform)
		return (MALLOC_FAIL);
	return (SUCCESS);
}

int	set_plane_transform(t_object *plane)
{
	t_tuple	forward;
	t_tuple	right;

	plane->direction = normalize_tuple(plane->direction);
	right = cross_product(plane->direction, vector(0, 0, 1));
	if (compare_doubles(tuple_magnitude(right), 0.0))
		right = cross_product(vector(0, 1, 0), plane->direction);
	right = normalize_tuple(right);
	forward = cross_product(right, plane->direction);
	forward = normalize_tuple(forward);
	plane->transform = tuples_to_matrix(plane->direction, right, forward, plane->position);
	if (!plane->transform)
		return (MALLOC_FAIL);
	return (SUCCESS);
}

int	set_cylinder_transform(t_object *cylinder)
{
	t_tuple		forward;
	t_tuple		right;
	t_matrix	*scaling_matrix;
	t_matrix	*translation_matrix;

	cylinder->direction = normalize_tuple(cylinder->direction);
	right = cross_product(cylinder->direction, vector(0, 0, 1));
	if (compare_doubles(tuple_magnitude(right), 0.0))
		right = cross_product(vector(0, 1, 0), cylinder->direction);
	right = normalize_tuple(right);
	forward = cross_product(right, cylinder->direction);
	forward = normalize_tuple(forward);
	translation_matrix = tuples_to_matrix(cylinder->direction, right, forward, cylinder->position);
	if (!translation_matrix)
		return (MALLOC_FAIL);
	scaling_matrix = scaling(cylinder->diameter / 2, 1, cylinder->diameter / 2);
	if (!scaling_matrix)
		return (MALLOC_FAIL);
	cylinder->transform = multiply_matrices(translation_matrix, scaling_matrix);
	if (!cylinder->transform)
		return (MALLOC_FAIL);
	free_matrix(&translation_matrix);
	free_matrix(&scaling_matrix);
	return (SUCCESS);
}
