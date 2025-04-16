#include "../include/minirt.h"

// int	main(void)
// {
// 	t_data	data;

// 	init_data(&data);
	
// 	render_sphere(&data);
// 	if (mlx_image_to_window(data.mlx, data.canvas, 0, 0) < 0)
// 	{
// 		printf("Failure to put image to window\n");
// 		return (1);
// 	}
	
// 	mlx_key_hook(data.mlx, &key_hooks, (void *) &data);
// 	mlx_loop(data.mlx);
// 	mlx_terminate(data.mlx);

// 	printf("Exiting\n");
// 	return (0);
// }

int main(int argc, char *argv[])
{
	t_data data;
	t_scene scene;

	init_data(&data);
	init_mlx(&data);
	init_scene(&scene);
	data.scene = &scene;
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	if (parse_scene(argv[1], data.scene) != SUCCESS)
	{
		cleanup(data.scene);
		return (EXIT_FAILURE);
	}
	set_transforms(data.scene);
	
	
	data.cam = &data.scene->camera;
	camera(&data, radians(data.cam->fov));

	printf("Object transform:\n");
	print_matrix(data.scene->objects->transform);

	printf("Camera transform:\n");
	print_matrix(data.scene->camera.transform);

	t_ray ray;
	t_ray transformed_ray;

	ray = ray_for_pixel(data.cam, 173, 106);
	transformed_ray = transform_ray(&ray, data.scene->objects->inverse_transform);

	print_ray(ray);
	printf("transform ray:\n");
	print_ray(transformed_ray);

	t_x *_hit;
	t_x *xs_list;

	xs_list = sphere_intersect(&transformed_ray, data.scene->objects);
	_hit = hit(xs_list);
	if (_hit && _hit->hit)
	{
		printf("Hit: %f\n", _hit->t);
	}
	else
	{
		printf("No hit\n");
	}
	render_scene(&data);
	mlx_key_hook(data.mlx, &key_hooks, (void *) &data);
	mlx_mouse_hook(data.mlx, &mouse_hook, (void*) &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);

	cleanup(data.scene);
	return (0);
}
