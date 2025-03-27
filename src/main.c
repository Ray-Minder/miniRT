#include "../include/minirt.h"

void	init_mlx(t_data	*data)
{
	data->height = 600;
	data->width = 800;
	data->mlx = mlx_init(data->width, data->height, "MINIRT", false);
}

int	main(void)
{
	t_data		data;
	mlx_image_t	*img = NULL;

	init_mlx(&data);
	img = mlx_new_image(data.mlx, data.width, data.height);
	if (!img || (mlx_image_to_window(data.mlx, img, 800 / 2, 600 / 2) < 0))
		printf("Error\n");
	mlx_key_hook(data.mlx, &key_hooks, (void *) &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	printf("Exiting\n");
	return (0);
}
