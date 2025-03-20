#include "../../include/scene.h"
#include "../../include/parser.h"

int	count_tokens(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

int	parse_ambient_light(char **line, t_scene *scene)
{
	int			error;

	if (scene->ambient_light.is_set)
		return (TOO_MANY_AMBIENT_LIGHTS);
	scene->ambient_light.is_set = true;
	if (count_tokens(line) != 3)
		return (INVALID_ARG_COUNT);
	if (parse_double(line[1], &scene->ambient_light.strength) != SUCCESS)
		return (INVALID_DOUBLE);
	if (scene->ambient_light.strength < 0 || scene->ambient_light.strength > 1)
		return (DOUBLE_OUT_OF_RANGE);
	error = parse_color(line[2], &scene->ambient_light.color);
	if (error != SUCCESS)
		return (error);
	return (SUCCESS);
}

int	parse_camera(char **line, t_scene *scene)
{
	int			error;

	if (scene->camera.is_set)
		return (TOO_MANY_CAMERAS);
	scene->camera.is_set = true;
	if (count_tokens(line) != 4)
		return (INVALID_ARG_COUNT);
	error = parse_tuple(line[1], &scene->camera.position);
	if (error != SUCCESS)
		return (error);
	error = parse_tuple(line[2], &scene->camera.forward);
	if (error != SUCCESS)
		return (error);
	error = parse_double(line[3], &scene->camera.fov);
	if (scene->camera.fov < 0 || scene->camera.fov >= 180)
		return (FOV_OUT_OF_RANGE);
	if (error != SUCCESS)
		return (error);
	return (SUCCESS);
}

int	parse_light(char **line, t_scene *scene)
{
	int			error;

	if (scene->light.is_set)
		return (TOO_MANY_LIGHTS);
	scene->light.is_set = true;
	if (count_tokens(line) != 4)
		return (INVALID_ARG_COUNT);
	error = parse_tuple(line[1], &scene->light.position);
	if (error != SUCCESS)
		return (error);
	error = parse_double(line[2], &scene->light.brightness);
	if (error != SUCCESS)
		return (error);
	error = parse_color(line[3], &scene->light.color);
	if (error != SUCCESS)
		return (error);
	return (0);
}
