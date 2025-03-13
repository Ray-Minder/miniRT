#include "../../include/scene.h"
#include "../../include/parser.h"
#include "../../libft/libft.h"
#include "../../include/get_next_line.h"
#include <fcntl.h>
#include <stdbool.h>

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


int	parse_line(char *line, t_scene *scene)
{
	const char	*elements[6] = {"A", "C", "L", "sp", "pl", "cy"};
	int (*p[6]) (char**, t_scene*) = {parse_ambient_light, parse_camera, parse_light, parse_sphere, parse_plane, parse_cylinder};
	char		**split_line;
	char		*trimmed_line;
	int error;
	
	error = 0;
	trimmed_line = ft_strtrim(line, "\n");
	split_line = ft_split(trimmed_line, ' ');
	free(trimmed_line);
	if (!split_line)
		return (SPLIT_ERROR);
	for (int i = 0; i < 6; i++)
	{
		if (ft_strncmp(split_line[0], elements[i], ft_strlen(elements[i]) + 1) == 0)
		{
			return (p[i](split_line, scene));
			break ;
		}
		if (i == 5)
		{
			ft_free_ptrs(split_line);
			return (INVALID_ELEMENT);
		}
	}
	ft_free_ptrs(split_line);
	return (SUCCESS);
}

int parse_scene(char *filename, t_scene *scene)
{
	int file;
	char *line;
	int error;

	if (!verify_filename(filename))
		return (INVALID_FILENAME);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (NO_ACCESS);
	while ((line = get_next_line(file)))
	{
		if (line[0] != '\n')
		{
			error = parse_line(line, scene);
			if (error != SUCCESS)
			{
				free(line);
				close(file);
				return (error);
			}
		}			
		free(line);
	}
	close(file);
	printf("success\n");
	return (SUCCESS);
}
