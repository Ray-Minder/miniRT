#include "../../include/parser.h"
#include "../../include/scene.h"
#include <stdlib.h>

int	parse_sphere(char **line, t_scene *scene)
{
	t_object	*new_object;
	int			error;

	error = add_new_object(scene, &new_object);
	if (error != SUCCESS)
		return (error);
	new_object->type = SPHERE;
	if (count_tokens(line) != 4)
		return (INVALID_ARG_COUNT);
	error = parse_tuple(line[1], &new_object->position);
	if (error != SUCCESS)
		return (error);
	error = parse_double(line[2], &new_object->diameter);
	if (error != SUCCESS)
		return (error);
	error = parse_color(line[3], &new_object->color);
	if (error != SUCCESS)
		return (error);
	return (SUCCESS);
}

int	parse_plane(char **line, t_scene *scene)
{
	t_object	*new_object;
	int			error;

	error = add_new_object(scene, &new_object);
	if (error != SUCCESS)
		return (error);
	new_object->type = PLANE;
	if (count_tokens(line) != 4)
		return (INVALID_ARG_COUNT);
	error = parse_tuple(line[1], &new_object->position);
	if (error != SUCCESS)
		return (error);
	error = parse_tuple(line[2], &new_object->transform);
	if (error != SUCCESS)
		return (error);
	error = parse_color(line[3], &new_object->color);
	if (error != SUCCESS)
		return (error);
	return (SUCCESS);
}

int	parse_cylinder(char **line, t_scene *scene)
{
	t_object	*new_object;
	int			error;

	error = add_new_object(scene, &new_object);
	if (error != SUCCESS)
		return (error);
	new_object->type = CYLINDER;
	if (count_tokens(line) != 6)
		return (INVALID_ARG_COUNT);
	error = parse_tuple(line[1], &new_object->position);
	if (error != SUCCESS)
		return (error);
	error = parse_tuple(line[2], &new_object->transform);
	if (error != SUCCESS)
		return (error);
	error = parse_double(line[3], &new_object->diameter);
	if (error != SUCCESS)
		return (error);
	error = parse_double(line[4], &new_object->height);
	if (error != SUCCESS)
		return (error);
	error = parse_color(line[5], &new_object->color);
	if (error != SUCCESS)
		return (error);
	return (SUCCESS);
}
