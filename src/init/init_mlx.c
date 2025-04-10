#include "../../include/minirt.h"

void	init_mlx(t_data	*data)
{
	data->mlx = mlx_init(data->width, data->height, "MINIRT", false);
	if (!data->mlx)
	{
		print_error_msg("There was an error initiating mlx.\n");
		exit(EXIT_FAILURE);
	}
	data->canvas = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->canvas)
	{
		print_error_msg("There was an error creating a mlx image.\n");
		exit(EXIT_FAILURE);
	}
}
