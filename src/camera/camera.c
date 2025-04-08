#include "../../include/minirt.h"

void	camera(t_data *data, double field_of_view)
{
	data->cam->hsize = data->width;
	data->cam->vsize = data->height;
	data->cam->fov = field_of_view;
	// data->cam->transform = identity(4);
	// if (!data->cam->transform)
	// 	return ;
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
