#include "../../include/minirt.h"

void render_scene(t_scene *scene)
{
	t_data		data;
	t_ray		ray;
	t_tuple		r_position;
	t_tuple		ray_origin;
	t_tuple		ray_direction;
	t_x			*xs_list;
	t_x			*xs;
	t_x			*_hit;

	t_object *sphere;
	t_object *current_sphere;
	
	double		wall_z;
	double		wall_size;
	double		pixel_size;
	double		half;

	int			y;
	int			x;
	double		world_y;
	double		world_x;

	init_data(&data);

	ray_origin = point(0, 0, -5);

	wall_z = 10.0;
	wall_size = 7.0;
	pixel_size = wall_size / data.height;
	half  = wall_size / 2;
	xs_list = NULL;
	xs = NULL;
	_hit = NULL;

	if (scene->objects)
	{
		sphere = scene->objects;
		current_sphere = scene->objects;
	}
		
	// print_objects(sphere);
	y = -1;
	while (++y < data.height)
	{
		world_y = half - pixel_size * y;
		x = -1;
		// printf("y: %d\n", y);
		while (++x < data.width)
		{
			xs = NULL;
			_hit = NULL;
			world_x = -half + pixel_size * x;
			r_position = point(world_x, world_y, wall_z);
			ray_direction = normalize_tuple(subtract_tuples(r_position, ray_origin));
			ray = create_ray(ray_origin, ray_direction);
			printf("y: %d, x: %d\n", y, x);
			while(sphere)
			{
				xs = intersect(&ray, sphere);
				if (xs)
					add_intersection_node(&xs_list, xs);				
				sphere = sphere->next;
			}
			// printf("xs: %p\n", xs);
			_hit = hit(xs_list);
			if (_hit && _hit->hit)
			{
				t_color ambient;
				t_color diffuse;
				t_tuple hit_pos;

				hit_pos = position(ray, _hit->t);
				// printf("hit_pos: %f, %f, %f\n", hit_pos.x, hit_pos.y, hit_pos.z);
				// printf("normal: %f, %f, %f\n", normal_at_sphere(sphere, hit_pos).x, normal_at_sphere(sphere, hit_pos).y, normal_at_sphere(sphere, hit_pos).z);
				ambient = ambient_lighting(scene->ambient_light, _hit->object->color);
				diffuse = diffuse_lighting(scene->light, normal_at_sphere(_hit->object, hit_pos), hit_pos, _hit->object->color);
				// printf("diffuse: %f, %f, %f\n", diffuse.r, diffuse.g, diffuse.b);
				mlx_put_pixel(data.canvas, x, y, color_to_uint32(add_colors(ambient, diffuse)));
			}
			free_intersections_list(&xs_list);
			if (current_sphere)
				current_sphere = current_sphere->next;
			sphere = scene->objects->next;
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

