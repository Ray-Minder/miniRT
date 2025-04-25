#include "../../include/minirt.h"

//	=== Function Declarations ===

void		init_data(t_data *data);
static void	init_mlx(t_data	*data);

//	=== Function Definitions ===

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
	init_mlx(data);
	data->scene = ft_calloc(1, sizeof(t_scene));
	if (!data->scene)
		print_clean_and_exit(data, MALLOC_FAIL, EXIT_FAILURE);
}

static void	init_mlx(t_data	*data)
{
	data->mlx = mlx_init(data->width, data->height, "MINIRT", false);
	if (!data->mlx)
		print_clean_and_exit(data, MLX_ERROR, EXIT_FAILURE);
	data->canvas = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->canvas)
		print_clean_and_exit(data, MLX_ERROR, EXIT_FAILURE);
}
