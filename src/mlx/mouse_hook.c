#include "../../include/minirt.h"

//	=== Function Declarations ===

void	print_ray(t_ray ray);
t_x		*intersect_world_debug(t_data *data, t_ray *ray);
void	print_hit(t_x *hit);
void	print_comps(t_comps *comps);
t_tuple	normal_at_sphere_debug(t_object *object, t_tuple world_point);
t_tuple	normal_at_cylinder_debug(t_object *object, t_tuple world_point);
void	mouse_hook(enum mouse_key button, enum action action,
			enum modifier_key mods, void *param);

//	=== Function Definitions ===

void	print_ray(t_ray ray)
{
	printf("Ray:\n");
	printf("  Origin: ");
	print_tuple(ray.origin);
	printf("  Direction: ");
	print_tuple(ray.direction);
	printf("magnitude: %f\n", tuple_magnitude(ray.direction));
}

t_x	*intersect_world_debug(t_data *data, t_ray *ray)
{
	t_x			*xs_list;
	t_x			*xs;
	t_object	*object;
	t_x			*next;

	xs_list = NULL;
	object = data->scene->objects;
	while (object)
	{
		xs = intersect(data, ray, object);
		while (xs)
		{
			next = xs->next;
			if (xs && !compare_doubles(xs->t, 0))
			{
				add_intersection_node(&xs_list, xs);
				break ;
			}
			free(xs);
			xs = next;
		}
		object = object->next;
	}
	return (xs_list);
}

void	print_hit(t_x *hit)
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

void	print_comps(t_comps *comps)
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

t_tuple	normal_at_sphere_debug(t_object *object, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	if (!object)
		return (point(0, 0, 0));
	if (object->type != SPHERE)
	{
		ft_putstr_fd("Error: normal_at_sphere\n", 2);
		exit(EXIT_FAILURE);
	}
	printf("World point: ");
	print_tuple(world_point);
	object_point = multiply_matrix_by_tuple(object->inverse_transform,
			world_point);
	printf("Object point: ");
	print_tuple(object_point);
	object_normal = subtract_tuples(object_point, point(0, 0, 0));
	printf("Object normal: ");
	print_tuple(object_normal);
	world_normal = multiply_matrix_by_tuple(object->inverse_transpose,
			object_normal);
	printf("World normal: ");
	print_tuple(world_normal);
	world_normal.w = 0;
	printf("World normal normalized: ");
	print_tuple(normalize_tuple(world_normal));
	return (normalize_tuple(world_normal));
}

t_tuple	normal_at_cylinder_debug(t_object *object, t_tuple world_point)
{
	t_tuple	object_normal;
	t_tuple	object_point;
	t_tuple	world_normal;
	double	distance;

	printf("calucalating normal at cylinder\n");
	object_point = multiply_matrix_by_tuple(object->inverse_transform,
			world_point);
	object_normal = vector(object_point.x, 0, object_point.z);
	distance = object_point.x * object_point.x + object_point.z
		* object_point.z;
	printf("distance: %f\n", distance);
	if (distance < 1.0 && compare_doubles(object_point.y, object->height * 2))
	{
		printf("normal at cylinder top\n");
		object_normal = vector(0, 1, 0);
	}
	else if (distance < 1.0 && compare_doubles(object_point.y, 0.0))
	{
		printf("normal at cylinder bottom\n");
		object_normal = vector(0, -1, 0);
	}
	world_normal = multiply_matrix_by_tuple(object->inverse_transpose,
			object_normal);
	world_normal.w = 0;
	world_normal = normalize_tuple(world_normal);
	return (world_normal);
}

void	mouse_hook(enum mouse_key button, enum action action,
			enum modifier_key mods, void *param)
{
	t_data	*data;
	t_comps	*comps;
	t_tuple	normal;
	t_ray	ray;
	t_x		*xs_list;
	t_x		*_hit;
	int		x;
	int		y;

	data = (t_data *) param;
	// Print the mouse button and coordinates
	if (mods == MLX_SHIFT)
		printf("Shift key pressed\n");
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		printf("Mouse position: (%d, %d)\n", x, y);
		ray = ray_for_pixel(data->cam, x, y);
		xs_list = NULL;
		xs_list = intersect_world_debug(data, &ray);
		print_intersection_list(xs_list);
		_hit = hit(data, xs_list);
		if (_hit)
		{
			comps = prepare_computations(_hit, &ray);
			normal = vector(0, 0, 0);
			if (_hit->object->type == SPHERE)
				normal = normal_at_sphere_debug(_hit->object, comps->point);
			else if (_hit->object->type == CYLINDER)
				normal = normal_at_cylinder_debug(_hit->object, comps->point);
			print_tuple(normal);
			printf("hit t: %f\n", _hit->t);
			print_comps(comps);
		}
	}
}
