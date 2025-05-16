/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_objects.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:13:41 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:13:42 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

int	parse_sphere(char **line, t_scene *scene);
int	parse_plane(char **line, t_scene *scene);
int	parse_cylinder(char **line, t_scene *scene);

//	=== Function Definitions ===

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
	error = parse_tuple(line[1], &new_object->pos);
	if (error != SUCCESS)
		return (error);
	new_object->pos.w = 1;
	error = parse_double(line[2], &new_object->diameter);
	if (error != SUCCESS)
		return (error);
	error = parse_color(line[3], &new_object->color);
	if (error != SUCCESS)
		return (error);
	if (new_object->diameter <= 0)
		return (DOUBLE_OUT_OF_RANGE);
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
	error = parse_tuple(line[1], &new_object->pos);
	if (error != SUCCESS)
		return (error);
	new_object->pos.w = 1;
	error = parse_tuple(line[2], &new_object->dir);
	if (error != SUCCESS)
		return (error);
	new_object->dir.w = 0;
	error = parse_color(line[3], &new_object->color);
	if (error != SUCCESS)
		return (error);
	if (compare_doubles(tuple_magnitude(new_object->dir), 0.0))
		return (INVALID_DIRECTION_VECTOR);
	return (SUCCESS);
}
