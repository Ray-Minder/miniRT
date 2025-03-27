#include "../../include/minirt.h"

void	init_mlx(t_data	*data)
{
	data->height = MIN_WINDOW_HEIGHT;
	data->width = MIN_WINDOW_WIDTH;
	data->mlx = mlx_init(data->width, data->height, "MINIRT", false);
	data->canvas = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->canvas)
		printf("Error initiating img.\n");
}
