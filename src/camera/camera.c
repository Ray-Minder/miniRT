#include "../../include/minirt.h"

//	=== Function Declarations ===

void	set_up_camera(t_data *data);

//	=== Function Definitions ===

/**
 * @brief Initializes the camera with the given field of view.
 * 
 * @param data Pointer to the data structure containing camera and scene information.
 * @param field_of_view The field of view in radians.
 * 
 * This function sets the camera's horizontal and vertical size, field of view,
 * inverse transformation matrix, origin, half view, aspect ratio, half height,
 * half width, and pixel size based on the provided field of view.
 * It also calculates the camera's transformation matrix.
 */
void	set_up_camera(t_data *data)
{
	data->cam = &data->scene->camera;
	data->cam->hsize = data->width;
	data->cam->vsize = data->height;
	data->cam->fov = radians(data->scene->camera.fov);
	data->cam->inverse_transform = invert_matrix(data->cam->transform);
	if (!data->cam->inverse_transform)
	{
		// print_error_msg("There was an error inverting the camera matrix.\n"); INVERT_MATRIX
		print_clean_and_exit(data, MALLOC_FAIL, EXIT_FAILURE);
	}
	data->cam->origin = multiply_matrix_by_tuple(data->cam->inverse_transform, point(0, 0, 0));
	data->cam->half_view = tan(data->cam->fov / 2);
	data->cam->aspect = data->cam->hsize / data->cam->vsize;
	if (data->cam->aspect >= 1)
	{
		data->cam->half_height = data->cam->half_view / data->cam->aspect;
		data->cam->half_width = data->cam->half_view;
	}
	else
	{
		data->cam->half_height = data->cam->half_view;
		data->cam->half_width = data->cam->half_view * data->cam->aspect;
	}
	data->cam->pixel_size = (data->cam->half_width * 2) / data->cam->hsize;
}
