#include "../include/minirt.h"

void	init_mlx(t_data	*data)
{
	data->height = 600;
	data->width = 800;
	data->mlx = mlx_init(data->width, data->height, "MINIRT", false);
}


int	main(void)
{
	t_data	data;

	init_mlx(&data);

	mlx_image_t	*img = mlx_new_image(data.mlx, 256, 256);
	if (!img || (mlx_image_to_window(data.mlx, img, 0, 0) < 0))
		printf("Error\n");
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_key_hook(data.mlx, &key_hooks, (void *) &data);
	mlx_loop(data.mlx);
	printf("Test\n");
	return (0);
}
