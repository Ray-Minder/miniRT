#include "../../include/minirt.h"

void	camera(t_data *data, double field_of_view)
{
	data->cam->hsize = data->width;
	data->cam->vsize = data->height;
	data->cam->fov = field_of_view;
	data->cam->inverse_transform = invert_matrix(data->cam->transform);
	if (!data->cam->inverse_transform)
	{
		print_error_msg("There was an error inverting the camera matrix.\n");
		exit(EXIT_FAILURE); //Clean up memory from data
	}
	data->cam->origin = multiply_matrix_by_tuple(data->cam->inverse_transform, point(0, 0, 0));
	data->cam->half_view = tan(field_of_view / 2);
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
