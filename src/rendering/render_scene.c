/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:06:57 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:06:58 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

static void	render_row(void *param);
void		render_scene(t_data *data);

//	=== Function Definitions ===

static void	render_row(void *param)
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
		color = color_at(data, &ray);
		mlx_put_pixel(data->canvas, x, data->current_row,
			color_to_uint32(color));
	}
	data->current_row++;
}

void	render_scene(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->canvas, 0, 0) < 0)
	{
		print_clean_and_exit(data, MLX_ERROR, EXIT_FAILURE);
	}
	mlx_loop_hook(data->mlx, &render_row, (void *) data);
}
