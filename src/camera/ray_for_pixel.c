#include "../../include/minirt.h"

# define X 0
# define Y 1

t_ray	ray_for_pixel(t_camera *camera, int x, int y)
{
	double	offset[2];
	double	world[2];
	t_tuple	pixel;
	t_tuple	direction;

	printf("pixel_size: %f\n", camera->pixel_size);
	printf("half_width: %f\n", camera->half_width);
	printf("half_height: %f\n", camera->half_height);
	printf("cam hsize: %f\n", camera->hsize);
	printf("cam vsize: %f\n", camera->vsize);

	offset[X] = (x + 0.5) * camera->pixel_size;
	offset[Y] = (y + 0.5) * camera->pixel_size;
	world[X] = camera->half_width - offset[X];
	world[Y] = camera->half_height - offset[Y];
	pixel = multiply_matrix_by_tuple(camera->inverse_transform, point(world[X], world[Y], -1));
	direction = normalize_tuple(subtract_tuples(pixel, camera->origin));
	return (create_ray(camera->origin, direction));
}

// t_ray		ray;
// 	t_tuple		pixel;
// 	t_tuple		origin;
// 	t_tuple		direction;

// 	pixel = pixel_at(camera, x, y);
// 	origin = camera->position;
// 	direction = subtract_tuples(pixel, origin);
// 	ray.origin = origin;
// 	ray.direction = normalize_tuple(direction);
// 	return (ray);
