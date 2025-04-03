#include "../../include/minirt.h"

//	=== Function Declarations ===

void	init_data(t_data *data);
void	init_scene(t_data *data);


//	=== Function Definitions ===

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
	init_scene(data);
	init_mlx(data);
}

void	init_scene(t_data *data)
{
	if (!data->scene)
		data->scene = ft_calloc(1, sizeof(t_scene));
	if (!data->scene)
	{
		printf("Failed to allocate memory for the scene structure.\n");
		exit(EXIT_FAILURE);
	}
	data->scene->objects = NULL;
	// data->scene->camera = NULL;
	// data->scene->light = NULL;
	data->scene->ambient_light.color = color(1.0, 1.0, 1.0); //Default value
	data->scene->ambient_light.brightness = 1.0;
	// data->scene->ambient_light.is_set = true;
}
