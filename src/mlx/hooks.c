#include "../../include/minirt.h"

void print_ray(t_ray ray);

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("Closing the window\n");
		mlx_close_window(data->mlx);
	}
}

t_x *intersect_world_debug(t_scene *scene, t_ray *ray)
{
	t_x			*xs_list;
	t_x			*xs;
	t_object	*object;
	t_ray		transformed_ray;

	xs_list = NULL;
	object = scene->objects;
	while (object)
	{
		xs = intersect(ray, object);
		transformed_ray = transform_ray(ray, object->inverse_transform);
		printf("transformed ray:\n");
		print_ray(transformed_ray);
		if (xs && !compare_doubles(xs->t, 0))
		{
			printf("transformed ray:\n");
			print_ray(transformed_ray);
			add_intersection_node(&xs_list, xs);
		}
		object = object->next;
	}
	return (xs_list);
}

void print_hit(t_x *hit)
{
	if (hit)
	{
		printf("Hit: %f\n", hit->t);
	}
	else
	{
		printf("No hit\n");
	}
}

void print_comps(t_comps *comps)
{
	if (comps)
	{
		printf("Comps:\n");
		printf("  Hit: %f\n", comps->hit->t);
		printf("  Point: ");
		print_tuple(comps->point);
		printf("  Eyev: ");
		print_tuple(comps->eyev);
		printf("  Normalv: ");
		print_tuple(comps->normalv);
	}
	else
	{
		printf("No comps\n");
	}
}

t_tuple normal_at_sphere_debug(t_object *object, t_tuple world_point)
{
	t_tuple object_point;
	t_tuple object_normal;
	// t_tuple world_point;
	t_tuple world_normal;

	if (object->type != SPHERE)
	{
		ft_putstr_fd("Error: normal_at_sphere\n", 2);
		exit(EXIT_FAILURE);
	}
	printf("World point: ");
	print_tuple(world_point);
	object_point = multiply_matrix_by_tuple(invert_matrix(object->transform), world_point);
	printf("Object point: ");
	print_tuple(object_point);
	// object_point = multiply_matrix_by_tuple(invert_matrix(identity(4)), world_point);
	object_normal = subtract_tuples(object_point, point(0, 0, 0));
	printf("Object normal: ");
	print_tuple(object_normal);
	world_normal = multiply_matrix_by_tuple(transpose_matrix(invert_matrix(object->transform)), object_normal);
	printf("World normal: ");
	print_tuple(world_normal);
	world_normal.w = 0;
	// world_normal = subtract_tuples(world_point, object->position);
	printf("World normal normalized: ");
	print_tuple(normalize_tuple(world_normal));
	return (normalize_tuple(world_normal));
}

void print_ray(t_ray ray)
{
	printf("Ray:\n");
	printf("  Origin: ");
	print_tuple(ray.origin);
	printf("  Direction: ");
	print_tuple(ray.direction);
	printf("magnitude: %f\n", tuple_magnitude(ray.direction));
}

void mouse_hook(enum mouse_key button, enum action action, enum modifier_key mods, void *param)
{
	t_data	*data;
	t_comps *comps;
	data = (t_data *) param;
    // Print the mouse button and coordinates
	int x;
	int y;

	if (mods == MLX_SHIFT)
	{
		printf("Shift key pressed\n");
	}

	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		printf("Mouse position: (%d, %d)\n", x, y);
		t_ray ray;
		ray = ray_for_pixel(data->cam, x, y);
		print_ray(ray);

		t_x *xs_list;
		t_x *_hit;
		xs_list = intersect_world_debug(data->scene, &ray);
		// print_intersection_list(xs_list);
		_hit = hit(xs_list);
		// print_hit(_hit);
		comps = prepare_computations(_hit, &ray);
		normal_at_sphere_debug(_hit->object, comps->point);
		printf("hit t: %f\n", _hit->t);
		// print_comps(comps);
	}	
}
