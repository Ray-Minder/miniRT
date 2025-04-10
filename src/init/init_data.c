#include "../../include/minirt.h"

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->canvas = NULL;
	data->scene = NULL;
	data->cam = NULL;
	data->light = NULL;
	data->width = WINDOW_WIDTH;
	data->height = WINDOW_HEIGHT;
	data->current_row = 0;
}
