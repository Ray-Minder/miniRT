#include "../include/minirt.h"

t_object	create_sphere(t_tuple position, double diameter, t_color color)
{
	t_object sphere;
	t_matrix *translation_matrix;
	t_matrix *scaling_matrix;

	sphere.type = SPHERE;
	sphere.diameter = diameter;
	sphere.position = position;
	sphere.material.color = color;
	sphere.material.ambient = 0.1;
	sphere.material.diffuse = 0.5;
	sphere.material.specular = 0.9;
	sphere.material.shininess = 200;

	translation_matrix = translate_from_tuple(position);
	if (!translation_matrix)
	{
		printf("Failed to allocate memory for translation matrix\n");
		exit(EXIT_FAILURE);
	}
	scaling_matrix = scaling(diameter / 2, diameter / 2, diameter / 2);
	if (!scaling_matrix)
	{
		printf("Failed to allocate memory for scaling matrix\n");
		free_matrix(&translation_matrix);
		exit(EXIT_FAILURE);
	}
	sphere.transform = multiply_matrices(translation_matrix, scaling_matrix);
	free_matrix(&translation_matrix);
	free_matrix(&scaling_matrix);
	if (!sphere.transform)
	{
		printf("Failed to allocate memory for sphere transform\n");
		exit(EXIT_FAILURE);
	}
	sphere.inverse_transform = invert_matrix(sphere.transform);	
	if (!sphere.inverse_transform)
	{
		printf("Failed to allocate memory for sphere inverse transform\n");
		free_matrix(&sphere.transform);
		exit(EXIT_FAILURE);
	}
	sphere.next = NULL;
	return (sphere);
}

t_camera create_camera(t_tuple position, t_tuple forward, double fov)
{
	t_camera camera;
	t_matrix *transform;

	camera.position = position;
	camera.forward = forward;
	camera.fov = fov;
	camera.transform = view_transform(position, forward);
	if (!camera.transform)
	{
		printf("Failed to allocate memory for camera transform\n");
		exit(EXIT_FAILURE);
	}
	camera.inverse_transform = invert_matrix(camera.transform);
	if (!camera.inverse_transform)
	{
		printf("Failed to allocate memory for camera inverse transform\n");
		free_matrix(&camera.transform);
		exit(EXIT_FAILURE);
	}
}

int main()
{
	t_object left_sphere;
	t_object center_sphere;
	t_object right_sphere;

	left_sphere = create_sphere(point(-1, 0, 0), 2, color(1, 0, 0));
	center_sphere = create_sphere(point(0, 0, 0), 2, color(0, 1, 0));
	right_sphere = create_sphere(point(1, 0, 0), 2, color(0, 0, 1));

	t_light light;
	light.position = point(-10, 10, -10);
	light.color = color(1, 1, 1);
	light.brightness = 0.8;

	t_camera camera;
	camera = create_camera(point(0, 0, -5), vector(0, 0, 1), 90);
	
	
	
}