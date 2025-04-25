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
		objects->inv_transform = invert_matrix(objects->transform);
		if (!objects->inv_transform)
			return (MALLOC_FAIL);
		objects->inv_transpose = transpose_matrix(objects->inv_transform);
		if (!objects->inv_transpose)
			return (MALLOC_FAIL);
		objects = objects->next;
	}
	return (SUCCESS);
}

int	set_sphere_transform(t_object *sphere)
{
	t_matrix		*scale;
	t_matrix		*translate;
	const double	diameter = sphere->diameter / 2;

	translate = translate_from_tuple(sphere->pos);
	if (!translate)
		return (MALLOC_FAIL);
	scale = scaling(diameter, diameter, diameter);
	if (!scale)
		return (MALLOC_FAIL);
	sphere->transform = multiply_matrices(translate, scale);
	free_matrix(&translate);
	free_matrix(&scale);
	if (!sphere->transform)
		return (MALLOC_FAIL);
	return (SUCCESS);
}

int	set_plane_transform(t_object *plane)
{
	t_tuple	forward;
	t_tuple	right;

	plane->dir = normalize_tuple(plane->dir);
	right = cross_product(plane->dir, vector(0, 0, 1));
	if (compare_doubles(tuple_magnitude(right), 0.0))
		right = cross_product(vector(0, 1, 0), plane->dir);
	right = normalize_tuple(right);
	forward = cross_product(right, plane->dir);
	forward = normalize_tuple(forward);
	plane->transform = tuples_to_matrix(plane->dir, right, forward, plane->pos);
	if (!plane->transform)
		return (MALLOC_FAIL);
	return (SUCCESS);
}

int	set_cylinder_transform(t_object *cyl)
{
	t_tuple		forward;
	t_tuple		right;
	t_matrix	*scale;
	t_matrix	*translate;

	cyl->dir = normalize_tuple(cyl->dir);
	right = cross_product(cyl->dir, vector(0, 0, 1));
	if (compare_doubles(tuple_magnitude(right), 0.0))
		right = cross_product(vector(0, 1, 0), cyl->dir);
	right = normalize_tuple(right);
	forward = cross_product(right, cyl->dir);
	forward = normalize_tuple(forward);
	translate = tuples_to_matrix(cyl->dir, right, forward, cyl->pos);
	if (!translate)
		return (MALLOC_FAIL);
	scale = scaling(cyl->diameter / 2, 1, cyl->diameter / 2);
	if (!scale)
		return (MALLOC_FAIL);
	cyl->transform = multiply_matrices(translate, scale);
	if (!cyl->transform)
		return (MALLOC_FAIL);
	free_matrix(&translate);
	free_matrix(&scale);
	return (SUCCESS);
}
