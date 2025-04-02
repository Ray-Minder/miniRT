#include "../../include/minirt.h"

// Structure to hold rendering parameters calculated once
typedef struct s_render_params
{
	double wall_z;
	double wall_size;
	double pixel_size;
	double half_wall;
	t_tuple ray_origin;
}	t_render_params;

// Structure to hold temporary scene data for this test function
typedef struct s_scene_data
{
	t_object sphere;
	t_light light;
	t_ambient_light ambient_light;
}	t_scene_data;

// Initializes rendering parameters based on canvas size and view setup
static void init_render_params(t_render_params *params, int width, int height)
{
	// Ray origin point
	params->ray_origin = point(0, 0, -5);
	// Wall position and size
	params->wall_z = 10.0;
	params->wall_size = 7.0;
	// Calculate pixel size based on canvas height (assuming square pixels)
	params->pixel_size = params->wall_size / height;
	// Calculate half wall size for coordinate mapping
	params->half_wall = params->wall_size / 2.0;
	(void)width; // Mark width as unused for now if pixel_size depends only on height
}

// Sets up the hardcoded scene elements for the test render
static void setup_scene_data(t_scene_data *scene)
{
	// Define the sphere properties
	scene->sphere.type = SPHERE;
	scene->sphere.position = point(0, 0, 0); // Position used by normal_at, etc.
	scene->sphere.transform = identity(4);	 // Start with identity transform
											 // Apply transformations if needed, e.g., scaling
	// t_matrix *scaling_matrix = scaling(1, 1, 1); // Example diameter 2
	// set_transform(&scene->sphere, scaling_matrix); // Set transform properly
	// Note: The original code used sphere.diameter = 2. The book uses unit spheres
	// and scaling transforms. Let's assume a unit sphere scaled if needed.
	// If you handle diameter directly in intersect/normal_at, adapt accordingly.
	// For now, assume unit sphere at origin.

	// Define the sphere's material
	scene->sphere.material.color = color(1.0, 0.2, 1.0); // Base color
	scene->sphere.material.ambient = 0.1;				 // Lower ambient reflection
	scene->sphere.material.diffuse = 0.9;				 // High diffuse reflection
	scene->sphere.material.specular = 0.9;				 // High specular reflection
	scene->sphere.material.shininess = 200.0;			 // Sharp highlight

	// Define the scene's ambient light
	scene->ambient_light.color = color(1.0, 1.0, 1.0); // White ambient light
	scene->ambient_light.brightness = 0.1;			   // Low ambient intensity

	// Define the point light source
	scene->light.position = point(-10, 10, -10); // Light position
	scene->light.color = color(1, 1, 1);		 // White light
	scene->light.brightness = 1;				 // Full brightness
}

// Calculates the color for a single pixel based on ray intersection and lighting
static t_color compute_pixel_color(int x, int y, t_render_params *params, t_scene_data *scene)
{
	t_tuple	world_pos;
	t_tuple	ray_direction;
	t_ray	ray;
	t_x		*xs;
	t_x		*_hit;
	t_color	final_color;

	// Calculate world coordinates for the pixel
	world_pos.x = -params->half_wall + params->pixel_size * x;
	world_pos.y = params->half_wall - params->pixel_size * y;
	world_pos.z = params->wall_z;
	world_pos.w = 1.0; // It's a point

	// Calculate the ray direction from origin to the world position
	ray_direction = normalize_tuple(subtract_tuples(world_pos, params->ray_origin));
	ray = create_ray(params->ray_origin, ray_direction);

	// Find intersections with the sphere
	xs = intersect(&ray, &scene->sphere);
	_hit = hit(xs); // Find the closest hit

	if (_hit && _hit->hit) // Check if hit is valid
	{
		t_tuple point;
		t_tuple eyev;
		t_tuple normalv;

		// Calculate intersection point, eye vector, and normal vector
		point = position(ray, _hit->t); // Use _hit->t (corrected from _hit->hit)
		eyev = negate_tuple(ray.direction);
		normalv = normal_at_sphere(&scene->sphere, point); // Pass sphere object

		final_color = lighting(scene->sphere.material, scene->light, point, eyev, normalv, scene->ambient_light, false);

		// TODO: Loop here if you have multiple lights in the future
	}
	else
	{
		// Background color if no hit
		final_color = color(0.5, 0.5, 0.5); // Grey background
	}

	free_intersections_list(&xs); // Clean up intersection list
	return (final_color);
}

// Main rendering function for the sphere test scene
void render_sphere(t_data *data)
{
	t_render_params params;
	t_scene_data scene; // Holds sphere, lights for this test
	int x;
	int y;
	t_color pixel_color;

	// Setup rendering constants and scene objects
	init_render_params(&params, data->width, data->height);
	setup_scene_data(&scene); // Setup sphere, lights, material

	// Loop through each pixel on the canvas
	y = 0; // Norminette prefers initialization before loop
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			// Calculate the color for the current pixel
			pixel_color = compute_pixel_color(x, y, &params, &scene);

			// Put the calculated color onto the canvas
			mlx_put_pixel(data->canvas, x, y, color_to_uint32(pixel_color));
			x++;
		}
		y++;
	}
	// Note: The setup_scene_data creates temporary objects. In a real scene,
	// these would come from data->world or a similar structure populated by parsing.
	// Remember to free any allocated memory (like transforms) when done.
	free_matrix(&scene.sphere.transform); // Free identity matrix created
}
