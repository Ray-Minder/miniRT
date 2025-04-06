#include "../../include/minirt.h"

static void setup_default_scene(t_scene *scene)
{
	scene->objects = ft_calloc(1, sizeof(t_object));
	scene->objects->type = SPHERE;
	scene->objects->diameter = 2;
	scene->objects->position = point(0, 0, 0);

	scene->objects->material.color = color(1, 0, 0);
	scene->objects->material.ambient = 0.1;
	scene->objects->material.diffuse = 0.5;
	scene->objects->material.specular = 0.9;
	scene->objects->material.shininess = 200;
	
	scene->objects->transform = identity(4);
	scene->objects->next = NULL;



	scene->ambient_light.color = color(1, 1, 1);
	scene->ambient_light.brightness = 0.2;

	scene->light.position = point(-10, 10, -10);
	scene->light.color = color(1, 1, 1);
	scene->light.brightness = 0.8;
}

void	render_sphere(t_data *data)
{
	t_scene		scene;
	t_tuple		r_position;
	t_x			*xs;
	t_x			*_hit;

	t_render_params		params;

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
				t_color ambient;
				t_color diffuse;
				t_tuple hit_pos;

				hit_pos = position(params.ray, _hit->t);
				ambient = ambient_lighting(scene.ambient_light, scene.objects->material.color);
				diffuse = diffuse_lighting(scene.light, normal_at_sphere(scene.objects, hit_pos), hit_pos, scene.objects->material.color);
				mlx_put_pixel(data->canvas, x, y, color_to_uint32(add_colors(ambient, diffuse)));
			}
		}
	}
}

