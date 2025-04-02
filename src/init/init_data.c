#include "../../include/minirt.h"

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->canvas = NULL;
	data->light = NULL;
	data->cam = NULL;
	data->scene = NULL;
	data->width = WINDOW_WIDTH;
	data->height = WINDOW_HEIGHT;

	data->cam = ft_calloc(1, sizeof(t_camera));
	if (!data->cam)
	{
		printf("Failed camera allocation in init_data\n");
		return ;
	}
	init_mlx(data);
}
