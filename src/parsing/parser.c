/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:13:47 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 15:14:19 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

void	ft_free_ptrs(char **ptrs);
int		identify_and_parse_element(char **line, t_scene *scene);
int		process_line(char *line, t_scene *scene);
int		process_file_lines(int file, t_scene *scene);
void	parse_scene(t_data *data, char *filename);

//	=== Function Definitions ===

void	ft_free_ptrs(char **ptrs)
{
	int	i;

	i = 0;
	while (ptrs[i])
	{
		free(ptrs[i]);
		i++;
	}
	free(ptrs);
}

int	identify_and_parse_element(char **line, t_scene *scene)
{
	const char	*elements[6] = {"A", "C", "L", "sp", "pl", "cy"};
	int			(*p[6])(char**, t_scene*);
	int			i;

	p[0] = parse_ambient_light;
	p[1] = parse_camera;
	p[2] = parse_light;
	p[3] = parse_sphere;
	p[4] = parse_plane;
	p[5] = parse_cylinder;
	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(line[0], elements[i], ft_strlen(elements[i]) + 1) == 0)
			return (p[i](line, scene));
		i++;
	}
	return (INVALID_ELEMENT);
}

int	process_line(char *line, t_scene *scene)
{
	char		**split_line;
	char		*trimmed_line;
	int			error;

	error = 0;
	trimmed_line = ft_strtrim(line, "\n");
	split_line = ft_split(trimmed_line, ' ');
	free(trimmed_line);
	if (!split_line)
		return (SPLIT_ERROR);
	error = identify_and_parse_element(split_line, scene);
	ft_free_ptrs(split_line);
	return (error);
}

int	process_file_lines(int file, t_scene *scene)
{
	char	*line;
	int		error;
	int		i;

	line = get_next_line(file);
	i = 0;
	while (line)
	{
		if (line[0] != '\n')
		{
			error = process_line(line, scene);
			if (error != SUCCESS)
			{
				printf("Error\nOn line %d: %s\n", i + 1, get_error_msg(error));
				free(line);
				return (error);
			}
		}
		free(line);
		line = get_next_line(file);
		i++;
	}
	return (SUCCESS);
}

void	parse_scene(t_data *data, char *filename)
{
	int	file;
	int	error;

	if (!data || !data->scene)
		clean_and_exit(data, EXIT_FAILURE);
	if (!verify_filename(filename))
		print_clean_and_exit(data, INVALID_FILENAME, EXIT_FAILURE);
	file = open(filename, O_RDONLY);
	if (file == -1)
		print_clean_and_exit(data, NO_ACCESS, EXIT_FAILURE);
	error = process_file_lines(file, data->scene);
	if (error != SUCCESS)
		clean_and_exit(data, EXIT_FAILURE);
	if (close(file))
		print_error_msg("close in parse_scene");
	error = validate_scene(data->scene);
	if (error != SUCCESS)
		print_clean_and_exit(data, error, EXIT_FAILURE);
	error = set_transforms(data->scene);
	if (error != SUCCESS)
		print_clean_and_exit(data, error, EXIT_FAILURE);
}
