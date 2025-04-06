#include "../../include/minirt.h"

void	render_sphere(t_data *data)
{
	t_scene		scene;
	t_tuple		r_position;
	t_x			*xs;
	t_x			*_hit;

	t_render_params		params;
	t_comps				comps;

	t_color		final_color;

	int			y;
	int			x;
	double		world_y;
	double		world_x;

//Declarations
//-------------------------
//Definitions

	init_render_params(&params, data->width, data->height);
	setup_default_scene(&scene);

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
			xs = intersect(&params.ray, scene.objects);
			if (!xs)
				continue ;
			_hit = hit(xs);
			if (_hit && _hit->hit)
			{
				prepare_computations(&comps, _hit, &params.ray);
				t_tuple hit_pos;

				hit_pos = position(params.ray, _hit->t);
				final_color = lighting(&scene, &comps);
				// ambient = ambient_lighting(scene.ambient_light, scene.objects->material.color);
				// diffuse = diffuse_lighting(scene.light, normal_at_sphere(scene.objects, hit_pos), hit_pos, scene.objects->material.color);
				mlx_put_pixel(data->canvas, x, y, color_to_uint32(final_color));
			}
		}
	}
}

