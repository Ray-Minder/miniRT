#include "../include/minirt.h"

// int	main(void)
// {
// 	t_data	data;

// 	init_data(&data);
	
// 	render_sphere(&data);
// 	if (mlx_image_to_window(data.mlx, data.canvas, 0, 0) < 0)
// 	{
// 		printf("Failure to put image to window\n");
// 		return (1);
// 	}
	
// 	mlx_key_hook(data.mlx, &key_hooks, (void *) &data);
// 	mlx_loop(data.mlx);
// 	mlx_terminate(data.mlx);

// 	printf("Exiting\n");
// 	return (0);
// }

int main(int argc, char *argv[])
{
	t_scene scene;
	initialize_scene(&scene);
	
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
	set_transforms(&scene);
	print_objects(scene.objects);
	print_light(&scene.light);
	render_scene(&scene);
	cleanup(&scene);
	return (0);
}
