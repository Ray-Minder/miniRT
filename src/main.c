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
	t_data data;

	init_data(&data);
	init_mlx(&data);
	init_scene(data.scene);
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	if (parse_scene(argv[1], data.scene) != SUCCESS)
	{
		cleanup(data.scene);
		return (EXIT_FAILURE);
	}
	set_transforms(data.scene);
	data.cam = &data.scene->camera;
	camera(&data, radians(data.cam->fov));
	data.cam->transform = view_transform(data.cam->forward, data.cam->position);
	render_scene(&data);
	
	mlx_key_hook(data.mlx, &key_hooks, (void *) &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);

	cleanup(data.scene);
	return (0);
}
