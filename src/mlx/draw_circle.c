#include "../../include/rays.h"
#include "../../include/minirt.h"

# define RADIUS 1

mlx_image_t	*draw_circle(t_data *data, int radius)
{
	mlx_image_t	*circle;
	int			x;
	int			y;

	circle = mlx_new_image(data->mlx, radius * 2, radius * 2);
	y = -radius;
	while (++y <= radius)
	{
		x = -radius;
		while (++x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				mlx_put_pixel(circle, x + radius, y + radius, 0xFF0000FF); // White color
		}
	}
	return circle;
}
