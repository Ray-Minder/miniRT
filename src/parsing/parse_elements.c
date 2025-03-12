#include "../../include/scene.h"

int count_tokens(char **tokens)
{
	int count = 0;
	while (tokens[count])
		count++;
	return (count);
}
int parse_ambient_light(char **line, t_scene *scene)
{
	static int count = 0;
	count++;
	if (count > 1)
	{
		printf("Error: More than one ambient light found.\n");
		return (1);
	}
	if (!line || !scene)
		return (1);
	if (count_tokens(line) != 3)
		return (1);
	printf("ambient light\n");
	return (0);
}

int parse_camera(char **line, t_scene *scene)
{
	static int count = 0;
	count++;
	if (count > 1)
	{
		printf("Error: More than one camera found.\n");
		return (1);
	}
	if (!line || !scene)
		return (1);
	printf("camera\n");
	return (0);
}

int parse_light(char **line, t_scene *scene)
{
	static int count = 0;
	count++;
	if (count > 1)
	{
		printf("Error: More than one light found.\n");
		return (1);
	}
	if (!line || !scene)
		return (1);
	printf("light\n");
	return (0);
}

int parse_sphere(char **line, t_scene *scene)
{
	if (!line || !scene)
		return (1);
	printf("sphere\n");
	return (0);
}

int parse_plane(char **line, t_scene *scene)
{
	if (!line || !scene)
		return (1);
	printf("plane\n");
	return (0);
}

int parse_cylinder(char **line, t_scene *scene)
{
	if (!line || !scene)
		return (1);
	printf("cylinder\n");
	return (0);
}