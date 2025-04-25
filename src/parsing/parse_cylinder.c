#include "../../include/minirt.h"

static int	parse_cylinder_attributes(char **line, t_object *cylinder)
{
	int	error;

	error = parse_tuple(line[1], &cylinder->pos);
	if (error != SUCCESS)
		return (error);
	cylinder->pos.w = 1;
	error = parse_tuple(line[2], &cylinder->dir);
	if (error != SUCCESS)
		return (error);
	cylinder->dir.w = 0;
	error = parse_double(line[3], &cylinder->diameter);
	if (error != SUCCESS)
		return (error);
	error = parse_double(line[4], &cylinder->height);
	if (error != SUCCESS)
		return (error);
	error = parse_color(line[5], &cylinder->color);
	return (error);
}

static int	validate_cylinder_attributes(t_object *cylinder)
{
	if (compare_doubles(tuple_magnitude(cylinder->dir), 0.0))
		return (INVALID_DIRECTION_VECTOR);
	if (cylinder->diameter <= 0 || cylinder->height <= 0)
		return (DOUBLE_OUT_OF_RANGE);
	return (SUCCESS);
}

int	parse_cylinder(char **line, t_scene *scene)
{
	t_object	*new_object;
	int			error;

	if (count_tokens(line) != 6)
		return (INVALID_ARG_COUNT);
	error = add_new_object(scene, &new_object);
	if (error != SUCCESS)
		return (error);
	new_object->type = CYLINDER;
	error = parse_cylinder_attributes(line, new_object);
	if (error != SUCCESS)
		return (error);
	error = validate_cylinder_attributes(new_object);
	if (error != SUCCESS)
		return (error);
	return (SUCCESS);
}
