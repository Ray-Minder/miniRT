#include "../../include/minirt.h"

# define X 0
# define Y 1

t_ray	ray_for_pixel(t_camera *camera, int x, int y)
{
	double	offset[2];
	double	world[2];
	t_tuple	pixel;
	t_tuple	direction;

	offset[X] = (x + 0.5) * camera->pixel_size;
	offset[Y] = (y + 0.5) * camera->pixel_size;
	world[X] = camera->half_view - offset[X];
	world[Y] = camera->half_height - offset[Y];
	pixel = multiply_matrix_by_tuple(camera->inverse_transform, point(world[X], world[Y], -1));
	direction = normalize_tuple(subtract_tuples(pixel, camera->origin));
	return (create_ray(camera->origin, direction));
}
