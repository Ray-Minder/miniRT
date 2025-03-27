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
	if (set_transforms(&scene) != SUCCESS)
		printf("malloc fail\n");
	t_matrix *matrix;
	matrix = tuples_to_matrix(vector(0,1,0), vector(1,0,0), vector(0,0,1), point(0,0,0));
	print_matrix(matrix);

	printf("\nOBJECTS\n");
	print_objects(scene.objects);
	printf("\nCAMERA\n");
	print_matrix(scene.camera.transform);
	printf("\nLIGHT\n");
	print_matrix(scene.light.transform);
	cleanup(&scene);
	return (0);
}
