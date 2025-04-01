#include "../../include/minirt.h"

t_color	ambient_lighting(t_ambient_light ambient_light, t_color object_color)
{
	t_color	ambient;

	ambient = multiply_color_by_scalar(ambient_light.color, ambient_light.brightness);

	ambient = hadamard_product(ambient, object_color);
	return (ambient);
}

t_color	diffuse_lighting(t_light light, t_tuple normal, t_tuple position, t_color object_color)
{
	t_color	diffuse;
	// t_color scaled_color;
	t_tuple	light_direction;
	double	light_dot_normal;
	
	light_direction = normalize_tuple(subtract_tuples(light.position, position));
	light_dot_normal = dot_product(normal, light_direction);
	if (light_dot_normal < 0)
		diffuse = color(0, 0, 0);
	else
	{
		diffuse = multiply_color_by_scalar(object_color, light.brightness * light_dot_normal);
		diffuse = hadamard_product(diffuse, light.color);
	}

	return (diffuse);
}

t_color	lighting(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_color	effective_color;
	t_tuple	lightv;
	t_color	ambient = material.color;
	double	light_dot_normal;
	t_color	diffuse = material.color;
	t_color	specular = material.color;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	factor;

	effective_color = multiply_color_by_scalar(material.color, light.brightness);
	lightv = normalize_tuple(subtract_tuples(light.position, point));
	ambient = multiply_color_by_scalar(effective_color, material.ambient);

	light_dot_normal = dot_product(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = color(0, 0, 0);
		specular = color(0, 0, 0);
	}
	else
	{
		diffuse = multiply_color_by_scalar(effective_color, material.diffuse);
		diffuse = multiply_color_by_scalar(diffuse, light_dot_normal);
	}

	reflectv = reflect(negate_tuple(lightv), normalv);
	reflect_dot_eye = dot_product(reflectv, eyev);
	if (reflect_dot_eye <= 0)
	{
		specular = color(0, 0, 0);
	}
	else
	{
		factor = pow(reflect_dot_eye, material.shininess);
		specular = multiply_color_by_scalar(specular, light.brightness);
		specular = multiply_color_by_scalar(specular, material.specular);
		specular = multiply_color_by_scalar(specular, factor);
	}

	return (add_colors(add_colors(ambient, diffuse), specular));
}

// t_color lighting(t_light light, t_tuple normal, t_tuple light_position, t_color object_color)
// {
// 	t_color ambient;
// 	t_color diffuse;
// 	t_tuple	light_direction;
// 	double	light_dot_normal;

// 	// Ambient lighting
// 	ambient = ambient_lighting(, object_color);

// 	// Diffuse lighting
// 	light_direction = normalize_tuple(subtract_tuples(light_position, light.position));
// 	light_dot_normal = dot_product(normal, light_direction);
// 	if (light_dot_normal < 0)
// 		diffuse = color(0, 0, 0);
// 	else
// 		diffuse = multiply_color_by_scalar(object_color, light.brightness * light_dot_normal);

// 	// Combine ambient and diffuse
// 	return add_colors(ambient, diffuse);
// }