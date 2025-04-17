#include "../../include/minirt.h"

void	render_row(void *param)
{
	t_data	*data;
	int		x;
	t_ray	ray;
	t_color	color;

	data = (t_data *)param;
	if (data->current_row >= data->height)
		return ;
	x = -1;
	while (++x < data->width)
	{
		ray = ray_for_pixel(data->cam, x, data->current_row);
		color = color_at(data->scene, &ray);
		mlx_put_pixel(data->canvas, x, data->current_row, color_to_uint32(color));
	}
	data->current_row++;
}

void render_scene(t_data *data)
{
	// printf("In render scene\n");
	// print_objects(data->scene->objects);
	if (mlx_image_to_window(data->mlx, data->canvas, 0, 0) < 0)
	{
		print_error_msg("Failure to put image to window\n");
		//Clean memory
		exit(EXIT_FAILURE);
	}
	mlx_loop_hook(data->mlx, &render_row, (void *) data);
}
