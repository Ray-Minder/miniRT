#include "../../include/minirt.h"

t_tuple normal_at_sphere(t_object *object, t_tuple world_point)
{
	t_tuple object_point;
	t_tuple object_normal;
	// t_tuple world_point;
	t_tuple world_normal;

	if (object->type != SPHERE)
	{
		ft_putstr_fd("Error: normal_at_sphere() called on non-sphere object\n", 2);
		exit(EXIT_FAILURE);
	}
	object_point = multiply_matrix_by_tuple(invert_matrix(object->transform), world_point);
	// object_point = multiply_matrix_by_tuple(invert_matrix(identity(4)), world_point);
	object_normal = subtract_tuples(object_point, object->position);
	world_normal = multiply_matrix_by_tuple(transpose_matrix(invert_matrix(object->transform)), object_normal);
	world_normal.w = 0;
	return (normalize_tuple(world_normal));
}

t_tuple reflect(t_tuple in, t_tuple normal)
{
	t_tuple reflected;

	reflected = subtract_tuples(in, multiply_tuple_by_scalar(normal, 2 * dot_product(in, normal)));
	return (reflected);
}





// t_color lighting(t_light light, t_tuple normal, t_tuple light_position, t_color object_color) {
//     t_color ambient;
//     t_color diffuse;
//     t_tuple light_direction;
//     double light_dot_normal;

//     // Ambient lighting
//     ambient = multiply_color_by_scalar(object_color, );

//     // Diffuse lighting
//     light_direction = normalize_tuple(subtract_tuples(light_position, light.position));
//     light_dot_normal = dot_product(normal, light_direction);
//     if (light_dot_normal < 0)
//         diffuse = color(0, 0, 0);
// 	else
//     	diffuse = multiply_color_by_scalar(object_color, light.brightness * light_dot_normal);

//     // Combine ambient and diffuse
//     return add_colors(ambient, diffuse);
// }
