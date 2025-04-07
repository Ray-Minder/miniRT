#include "../../include/minirt.h"

t_camera *camera(double hsize, double vsize, double field_of_view)
{
	t_camera	*cam;

	cam = ft_calloc(1, sizeof(t_camera));
	if (!cam)
		return (NULL);
	cam->fov = field_of_view;
	cam->transform = identity_matrix(4);
	if (!cam->transform)
		return (free(cam), NULL);
	cam->half_view = tan(field_of_view / 2);
	cam->aspect = hsize / vsize;
	if (cam->aspect >= 1)
	{
		cam->half_height = cam->half_view / cam->aspect;
		cam->half_width = cam->half_view;
	}
	else
	{
		cam->half_height = cam->half_view;
		cam->half_width = cam->half_view * cam->aspect;
	}
	cam->pixel_size = (cam->half_width * 2) / hsize;
	return (cam);
}
