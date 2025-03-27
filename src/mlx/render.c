#include "../../include/minirt.h"

void	render_sphere(t_data *data)
{
	t_object	sphere;
	t_ray		ray;
	t_tuple		position;
	t_tuple		ray_origin;
	t_tuple		ray_direction;
	t_x			*xs;
	t_x			*_hit;

	double		wall_z;
	double		wall_size;
	double		pixel_size;
	double		half;

	int			y;
	int			x;
	double		world_y;
	double		world_x;

//Declarations
//-------------------------
//Definitions

	sphere.type = SPHERE;
	sphere.diameter = 2;
	sphere.position = point(0, 0, 0);
	sphere.transform = identity(4);

	ray_origin = point(0, 0, -5);
	
	wall_z = 10.0;
	wall_size = 7.0;
	pixel_size = wall_size / data->height;
	half  = wall_size / 2;

	y = -1;
	while (++y < data->height)
	{
		world_y = half - pixel_size * y;
		x = -1;
		while (++x < data->width)
		{
			world_x = -half + pixel_size * x;
			position = point(world_x, world_y, wall_z);
			ray_direction = normalize_tuple(subtract_tuples(position, ray_origin));
			ray = create_ray(ray_origin, ray_direction);
			xs = intersect(&ray, &sphere);
			if (!xs)
				continue ;
			_hit = hit(xs);
			if (_hit && _hit->hit)
				mlx_put_pixel(data->canvas, x, y, 0xFF0000FF);
		}
	}
	
}
