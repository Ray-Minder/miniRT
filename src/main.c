#include "../include/minirt.h"

int main(int argc, char *argv[])
{
	t_data data;
	t_scene scene;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	init_data(&data, &scene);
	init_mlx(&data);
	init_scene(data.scene);
	if (parse_scene(argv[1], data.scene) != SUCCESS)
	{
		cleanup(data.scene);
		return (EXIT_FAILURE);
	}
	set_transforms(data.scene);

	data.cam = &data.scene->camera;
	camera(&data, radians(data.cam->fov));

	render_scene(&data);
	
	mlx_key_hook(data.mlx, &key_hooks, (void *) &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);

	cleanup(data.scene);
	return (0);
}
