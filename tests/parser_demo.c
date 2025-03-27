#include "../include/parser.h"
#include "../include/minirt.h"

int main(int argc, char *argv[])
{
	t_scene scene;

	scene.objects = NULL;
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	if (parse_scene(argv[1], &scene) != SUCCESS)
	{
		cleanup(&scene);
		return (EXIT_FAILURE);
	}
	cleanup(&scene);
	return (0);
}