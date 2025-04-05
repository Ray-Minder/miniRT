#include "../../include/minirt.h"

void	render_sphere(t_data *data)
{
	t_ambient_light	ambient_light;
	t_object	sphere;
	t_ray		ray;
	t_tuple		r_position;
	t_tuple		ray_origin;
	t_tuple		ray_direction;
	t_x			*xs;
	t_x			*_hit;
	t_light		light;

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
	sphere.color = color(1, 1, 1);

	ambient_light.color = color(0.4, 0.2, .7);
	ambient_light.brightness = 0.2;
	light.position = point(10, 10, -10);
	light.color = color(1, .4, 0);
	light.brightness = .4;

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
			r_position = point(world_x, world_y, wall_z);
			ray_direction = normalize_tuple(subtract_tuples(r_position, ray_origin));
			ray = create_ray(ray_origin, ray_direction);
			xs = intersect(&ray, &sphere);
			if (!xs)
				continue ;
			_hit = hit(xs);
			if (_hit && _hit->hit)
			{
				t_color ambient;
				t_color diffuse;
				t_tuple hit_pos;

				hit_pos = position(ray, _hit->t);
				ambient = ambient_lighting(ambient_light, sphere.color);
				diffuse = diffuse_lighting(light, normal_at_sphere(&sphere, hit_pos), hit_pos, sphere.color);
				mlx_put_pixel(data->canvas, x, y, color_to_uint32(add_colors(ambient, diffuse)));
			}
		}
	}
	
}

void render_scene(t_scene *scene)
{
	t_data data;
	t_ray		ray;
	t_tuple		r_position;
	t_tuple		ray_origin;
	t_tuple		ray_direction;
	t_x			*xs_list;
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

	init_data(&data);

	ray_origin = point(0, 0, -5);

	wall_z = 10.0;
	wall_size = 7.0;
	pixel_size = wall_size / data.height;
	half  = wall_size / 2;
	xs_list = NULL;
	xs = NULL;
	_hit = NULL;

	x = 0;
	y = 0;
	t_object *sphere = scene->objects;
	// print_objects(sphere);
	while (y < data.height)
	{
		world_y = half - pixel_size * y;
		x = 0;
		// printf("y: %d\n", y);
		while (x < data.width)
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
				add_intersection_node(&xs_list, xs);
				if (!xs)
					continue ;
				_hit = hit(xs);
				if (_hit && _hit->hit)
				{
					t_color ambient;
					t_color diffuse;
					t_tuple hit_pos;

					hit_pos = position(ray, _hit->t);
					// printf("hit_pos: %f, %f, %f\n", hit_pos.x, hit_pos.y, hit_pos.z);
					// printf("normal: %f, %f, %f\n", normal_at_sphere(sphere, hit_pos).x, normal_at_sphere(sphere, hit_pos).y, normal_at_sphere(sphere, hit_pos).z);
					ambient = ambient_lighting(scene->ambient_light, sphere->color);
					diffuse = diffuse_lighting(scene->light, normal_at_sphere(sphere, hit_pos), hit_pos, sphere->color);
					// printf("diffuse: %f, %f, %f\n", diffuse.r, diffuse.g, diffuse.b);
					mlx_put_pixel(data.canvas, x, y, color_to_uint32(add_colors(ambient, diffuse)));
				}
				sphere = sphere->next;
			}
				
			sphere = scene->objects;
			x++;
		}
		y++;
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
// void minirt(void)