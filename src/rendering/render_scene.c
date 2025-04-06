#include "../../include/minirt.h"

void render_scene(t_scene *scene)
{
	t_data			data;
	t_tuple			r_position;
	t_x				*xs_list;
	t_x				*xs;
	t_x				*_hit;
	
	t_render_params params;
	t_comps			comps;

	t_object *sphere;

	int			y;
	int			x;
	double		world_y;
	double		world_x;

	init_data(&data);
	init_render_params(&params, data.width, data.height);

	xs_list = NULL;
	xs = NULL;
	_hit = NULL;

	sphere = scene->objects;
	// print_objects(sphere);
	y = -1;
	while (++y < data.height)
	{
		world_y = params.half_wall - params.pixel_size * y;
		x = -1;
		// printf("y: %d\n", y);
		while (++x < data.width)
		{
			xs = NULL;
			_hit = NULL;
			world_x = -params.half_wall + params.pixel_size * x;
			r_position = point(world_x, world_y, params.wall_z);
			params.ray.direction = normalize_tuple(subtract_tuples(r_position, params.ray.origin));
			printf("y: %d, x: %d\n", y, x);

			while(sphere)
			{
				xs = intersect(&params.ray, sphere);
				if (xs)
					add_intersection_node(&xs_list, xs);				
				sphere = sphere->next;
			}

			printf("xs: %p\n", xs);
			_hit = hit(xs_list);
			if (_hit && _hit->hit)
			{
				t_color final_color;

				prepare_computations(&comps, _hit, &params.ray);
				final_color = lighting(scene, &comps);
				mlx_put_pixel(data.canvas, x, y, color_to_uint32(final_color));
			}

			free_intersections_list(&xs_list);
			if (scene->objects)
				scene->objects = scene->objects->next;
			sphere = scene->objects;
		}
		// print_intersection_list(xs_list);
	}

	if (mlx_image_to_window(data.mlx, data.canvas, 0, 0) < 0)
	{
		printf("Failure to put image to window\n");
		return;
	}
	
	mlx_key_hook(data.mlx, &key_hooks, (void *) &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}

