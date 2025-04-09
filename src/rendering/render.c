#include "../../include/minirt.h"

//Uses data for putting pixel to image
//Passing cam and scene, even though they could be retrieved from data, to make it clear that it's these variables that the function uses
void	render(t_data *data, t_camera *cam, t_scene *scene)
{
	int		y;
	int		x;
	t_ray	ray;
	t_color	color;

	y = -1;
	while (++y < cam->vsize - 1)
	{
		x = -1;
		while (++x < cam->hsize - 1)
		{
			// printf("y: %d, x: %d\n", y, x);	
			ray = ray_for_pixel(cam, x, y);
			color = color_at(scene, &ray);
			mlx_put_pixel(data->canvas, x, y, color_to_uint32(color));
		}
	}
}
