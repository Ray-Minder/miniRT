#include "../../include/parser.h"
#include "../../include/minirt.h"

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
				ft_putstr_fd("Error on line ", 2);
				ft_putnbr_fd(i + 1, 2);
				ft_putstr_fd(": ", 2);
				free(line);
				return (print_error(error));
			}
		}
		free(line);
		line = get_next_line(file);
		i++;
	}
	return (SUCCESS);
}

int	parse_scene(char *filename, t_scene *scene)
{
	int	file;
	int	error;

	if (!verify_filename(filename))
		return (print_error(INVALID_FILENAME));
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (print_error(NO_ACCESS));
	error = process_file_lines(file, scene);
	close(file);
	if (error == SUCCESS)
		error = validate_scene(scene);
	if (error != SUCCESS)
		print_error(error);
	return (error);
}
