#include "../../include/minirt.h"

t_color	specular_lighting(t_light light, t_material material, double reflect_dot_eye)
{
	t_color	specular_color;
	double	factor;

	factor = pow(reflect_dot_eye, material.shininess);

	specular_color = multiply_color_by_scalar(light.color, material.specular * factor * light.brightness);
	return (specular_color);
}
