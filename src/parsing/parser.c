#include "../../include/scene.h"
#include "../../include/parser.h"
#include "../../libft/libft.h"
#include "../../include/get_next_line.h"
#include <fcntl.h>
#include <stdbool.h>

// double ft_atodbl(char *str)
// {
// 	double	result;
// 	double	power;
// 	int		sign;
// 	int		i;

// 	result = 0.0;
// 	power = 0.1;
// 	sign = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// }

void ft_free_ptrs(char **ptrs)
{
	int i;

	i = 0;
	while (ptrs[i])
	{
		free(ptrs[i]);
		i++;
	}
	free(ptrs);
}


int	parse_line(char *line)
{
	t_scene	scene;
	const char	*elements[6] = {"A", "C", "L", "sp", "pl", "cy"};
	int (*p[6]) (char**, t_scene*) = {parse_ambient_light, parse_camera, parse_light, parse_sphere, parse_plane, parse_cylinder};
	char		**split_line;
	char		*trimmed_line;

	trimmed_line = ft_strtrim(line, "\n");
	split_line = ft_split(trimmed_line, ' ');
	free(trimmed_line);
	if (!split_line)
	{
		ft_putstr_fd("Error splitting line: ", STDERR_FILENO);
		ft_putstr_fd(line, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return (4);
	}
	for (int i = 0; i < 6; i++)
	{
		if (ft_strncmp(split_line[0], elements[i], ft_strlen(elements[i]) + 1) == 0)
		{
			p[i](split_line, &scene);
			break ;
		}
		if (i == 5)
		{
			ft_putstr_fd("Invalid element: ", STDERR_FILENO);
			ft_putstr_fd(split_line[0], STDERR_FILENO);
			ft_putchar_fd('\n', STDERR_FILENO);
			ft_free_ptrs(split_line);
			return (5);
		}
	}
	ft_free_ptrs(split_line);
	return (0);
}

int parse_scene(char *filename)
{
	int file;
	char *line;

	if (!verify_filename(filename))
	{	
		ft_putstr_fd("Invalid filename extension: ", STDERR_FILENO);
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return (1);
	}
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		ft_putstr_fd("Error opening file: ", STDERR_FILENO);
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return (2);
	}
	while ((line = get_next_line(file)))
	{
		if (line[0] != '\n')
		{
			if (parse_line(line) != 0)
			{
				free(line);
				return (3);
			}
		}			
		free(line);
	}
	close(file);
	return (0);
}
