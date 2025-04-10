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
	if (mlx_image_to_window(data->mlx, data->canvas, 0, 0) < 0)
	{
		print_error_msg("Failure to put image to window\n");
		//Clean memory
		exit(EXIT_FAILURE);
	}
	mlx_loop_hook(data->mlx, &render_row, (void *) data);
}

// void render_scene(t_scene *scene)
// {
// 	t_data			data;
// 	t_tuple			r_position;
// 	t_x				*xs_list;
// 	t_x				*_hit;

// 	t_render_params params;
// 	t_comps			*comps;

// 	int			y;
// 	int			x;
// 	double		world_y;
// 	double		world_x;

// 	init_data(&data);
// 	init_render_params(&params, data.width, data.height);

// 	xs_list = NULL;
// 	_hit = NULL;
	
// 	// print_objects(sphere);
// 	y = -1;
// 	while (++y < data.height)
// 	{
// 		world_y = params.half_wall - params.pixel_size * y;
// 		x = -1;
// 		// printf("y: %d\n", y);
// 		while (++x < data.width)
// 		{
// 			_hit = NULL;
// 			world_x = -params.half_wall + params.pixel_size * x;
// 			r_position = point(world_x, world_y, params.wall_z);
// 			params.ray.direction = normalize_tuple(subtract_tuples(r_position, params.ray.origin));
// 			printf("y: %d, x: %d\n", y, x);

// 			xs_list = intersect_world(scene, &params.ray);

// 			_hit = hit(xs_list);
// 			if (_hit && _hit->hit)
// 			{
// 				t_color final_color;

// 				printf("Closest hit at t: %f for sphere at (%f, %f, %f)\n", _hit->t, _hit->object->position.x, _hit->object->position.y, _hit->object->position.z);
// 				comps = prepare_computations(_hit, &params.ray);
// 				final_color = lighting(scene, comps);
// 				mlx_put_pixel(data.canvas, x, y, color_to_uint32(final_color));
// 				ft_free((void **) &comps);
// 			}
// 			free_intersections_list(&xs_list);
// 		}

// 		// print_intersection_list(xs_list);
// 	}

// 	if (mlx_image_to_window(data.mlx, data.canvas, 0, 0) < 0)
// 	{
// 		printf("Failure to put image to window\n");
// 		return;
// 	}
	
// 	mlx_key_hook(data.mlx, &key_hooks, (void *) &data);
// 	mlx_loop(data.mlx);
// 	mlx_terminate(data.mlx);
// }