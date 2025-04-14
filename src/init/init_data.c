#include "../../include/minirt.h"

void	init_data(t_data *data, t_scene *scene)
{
	data->mlx = NULL;
	data->canvas = NULL;
	data->scene = scene;
	data->cam = NULL;
	data->light = NULL;
	data->width = WINDOW_WIDTH;
	data->height = WINDOW_HEIGHT;
	data->current_row = 0;
}
