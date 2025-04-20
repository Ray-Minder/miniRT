#include "../../include/minirt.h"

#define X 0
#define Y 1

//	=== Function Declarations ===

t_ray	ray_for_pixel(t_camera *camera, int x, int y);

//	=== Function Definitions ===

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
 * 
 * The pixel's position is calculated based on
 * the camera's half view, pixel size, and the pixel's coordinates.
 * The ray's direction is normalized to ensure it has a magnitude of 1.
 * 
 * The function uses the camera's inverse transformation matrix
 * to convert the pixel's coordinates from camera space to world space.
 * The resulting ray can be used for rendering.
 */
t_ray	ray_for_pixel(t_camera *camera, int x, int y)
{
	double	offset[2];
	double	cam_space_pos[2];
	t_tuple	world_pixel_pos;
	t_tuple	direction;

	offset[X] = (x + 0.5) * camera->pixel_size;
	offset[Y] = (y + 0.5) * camera->pixel_size;
	cam_space_pos[X] = camera->half_width - offset[X];
	cam_space_pos[Y] = camera->half_height - offset[Y];
	world_pixel_pos = multiply_matrix_by_tuple(camera->inverse_transform,
			point(cam_space_pos[X], cam_space_pos[Y], -1));
	direction = normalize_tuple(subtract_tuples(world_pixel_pos,
				camera->origin));
	return (create_ray(camera->origin, direction));
}
