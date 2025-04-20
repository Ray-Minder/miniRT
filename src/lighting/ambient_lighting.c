#include "../../include/minirt.h"

t_color ambient_lighting(t_ambient_light ambient_light, t_color object_color)
{
	t_color ambient;

	ambient = multiply_color_by_scalar(ambient_light.color, ambient_light.brightness);
	ambient = hadamard_product(ambient, object_color);
	return (ambient);
}
