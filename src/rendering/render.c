#include "../../include/minirt.h"

//Uses data for putting pixel to image
//Passing cam and scene, even though they could be retrieved from data, to make it clear that it's these variables that the function uses
void	render(t_data *data)
{
	int		y;
	int		x;
	t_ray	ray;
	t_color	color;

	y = -1;
	while (++y < data->cam->vsize - 1)
	{
		x = -1;
		while (++x < data->cam->hsize - 1)
		{
			ray = ray_for_pixel(data->cam, x, y);
			color = color_at(data, &ray);
			mlx_put_pixel(data->canvas, x, y, color_to_uint32(color));
		}
	}
}
