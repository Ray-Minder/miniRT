#include "../../include/minirt.h"

void init_render_params(t_render_params *params, int width, int height)
{
	(void) width;
	params->wall_z = 10.0;
	params->wall_size = 7.0;
	params->half_wall = params->wall_size / 2;
	params->pixel_size = params->wall_size / height;
	// params->world_position = point(0, 0, 0);
	params->ray.origin = point(0, 0, -5);
}

void setup_default_scene(t_scene *scene)
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

void	prepare_computations(t_comps *comps, t_x *hit, t_ray *ray)
{
	comps->hit = hit;
	comps->object = hit->object;
	comps->point = position(*ray, hit->t);
	comps->eyev = negate_tuple(ray->direction);
	comps->normalv = normal_at_sphere(comps->object, comps->point);
	comps->inside = false;
	if (dot_product(comps->normalv, comps->eyev) < 0)
	{
		comps->inside = true;
		comps->normalv = negate_tuple(comps->normalv);
	}
}


