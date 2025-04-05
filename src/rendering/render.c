#include "../../include/minirt.h"

// Initializes rendering parameters based on canvas size and view setup
static void init_render_params(t_render_params *params, int width, int height)
{
	// Wall position and size
	params->wall_z = 10.0;
	params->wall_size = 7.0;
	// Calculate pixel size based on canvas height (assuming square pixels)
	params->pixel_size = params->wall_size / height;
	(void)width; // Mark width as unused for now if pixel_size depends only on height
	// Calculate half wall size for coordinate mapping
	params->half_wall = params->wall_size / 2.0;
	

	params->ray.origin = point(0, 0, -5);
}

// Sets up the hardcoded scene elements for the test render
static void setup_default_scene(t_scene *scene)
{
	// Define the sphere properties
	scene->objects = malloc(sizeof(t_object)); // Allocate memory for the object
	if (!scene->objects)
	{
		perror("Failed to allocate memory for scene objects");
		exit(EXIT_FAILURE);
	}
	scene->objects->type = SPHERE;
	scene->objects->position = point(0, 0, 0);		// Position used by normal_at, etc.
	scene->objects->transform = identity(4);		// Start with identity transform
	// Apply transformations if needed, e.g., scaling
	// t_matrix *scaling_matrix = scaling(1, 1, 1);		// Example diameter 2
	// set_transform(scene->objects, scaling_matrix);	// Set transform properly

	// Define the sphere's material
	scene->objects->material.color = color(1.0, 0.2, 1.0);	// Base color
	scene->objects->material.ambient = 0.1;				 	// Lower ambient reflection
	scene->objects->material.diffuse = 0.9;					// High diffuse reflection
	scene->objects->material.specular = 0.9;				// High specular reflection
	scene->objects->material.shininess = 200.0;			 	// Sharp highlight

	// Define the scene's ambient light
	scene->ambient_light.color = color(1.0, 1.0, 1.0);	// White ambient light
	scene->ambient_light.brightness = 0.1;				// Low ambient intensity

	// Define the point light source
	scene->light.position = point(-10, 10, -10);	// Light position
	scene->light.color = color(1, 1, 1);			// White light
	scene->light.brightness = 1;					// Full brightness
}

// Main rendering function for the sphere test scene
void render_sphere(t_data *data)
{
	t_render_params		params;
	t_scene 			scene; // Holds sphere, lights for this test
	int					x;
	int					y;
	t_color 			pixel_color;

	// Setup rendering constants and scene objects
	init_render_params(&params, data->width, data->height);
	setup_default_scene(&scene); // Setup sphere, lights, material

	// Loop through each pixel on the canvas
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			// Calculate the color for the current pixel
			pixel_color = compute_pixel_color(x, y, &params, &scene);

			// Put the calculated color onto the canvas
			mlx_put_pixel(data->canvas, x, y, color_to_uint32(pixel_color));
		}
	}
	// Remember to free any allocated memory (like transforms) when done.
	// free_matrix(&scene->objects->transform); // Free identity matrix created
}
