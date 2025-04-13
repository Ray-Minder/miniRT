#include "../../include/minirt.h"

# define X 0
# define Y 1

/**
 * @brief Creates a ray for a specific pixel in the camera's view.
 * 
 * @param camera Pointer to the camera structure.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @return A ray object representing the ray for the specified pixel.
 * 
 * @note This function calculates the pixel's position in world space
 * and creates a ray that originates from the camera's position
 * and points towards the pixel.
 * The pixel's position is calculated based on
 * the camera's half view, pixel size, and the pixel's coordinates.
 * The ray's direction is normalized to ensure it has a magnitude of 1.
 * The function uses the camera's inverse transformation matrix
 * to convert the pixel's coordinates from camera space to world space.
 * The resulting ray can be used for rendering.
 */
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
