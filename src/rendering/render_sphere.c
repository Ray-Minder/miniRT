#include "../../include/minirt.h"

// void	render_sphere(t_data *data)
// {
// 	t_scene	*scene;

// }

void	render_sphere(t_data *data)
{
	t_ambient_light	ambient_light;
	t_object	sphere;
	t_tuple		r_position;
	t_x			*xs;
	t_x			*_hit;
	t_light		light;

	t_render_params		params;

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
	sphere.material.color = color(1, 0, 0);

	ambient_light.color = color(0.4, 0.2, .7);
	ambient_light.brightness = 0.2;
	light.position = point(10, 10, -10);
	light.color = color(1, .4, 0);
	light.brightness = .4;

	init_render_params(&params, data->width, data->height);

	y = -1;
	while (++y < data->height)
	{
		world_y = params.half_wall - params.pixel_size * y;
		x = -1;
		while (++x < data->width)
		{
			world_x = -params.half_wall + params.pixel_size * x;
			r_position = point(world_x, world_y, params.wall_z);
			params.ray.direction = normalize_tuple(subtract_tuples(r_position, params.ray.origin));
			xs = intersect(&params.ray, &sphere);
			if (!xs)
				continue ;
			_hit = hit(xs);
			if (_hit && _hit->hit)
			{
				t_color ambient;
				t_color diffuse;
				t_tuple hit_pos;

				hit_pos = position(params.ray, _hit->t);
				ambient = ambient_lighting(ambient_light, sphere.material.color);
				diffuse = diffuse_lighting(light, normal_at_sphere(&sphere, hit_pos), hit_pos, sphere.material.color);
				mlx_put_pixel(data->canvas, x, y, color_to_uint32(add_colors(ambient, diffuse)));
			}
		}
	}
}

