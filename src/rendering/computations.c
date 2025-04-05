#include "../../include/minirt.h"

// Calculates the color for a single pixel based on ray intersection and lighting
t_color compute_pixel_color(int x, int y, t_render_params *params, t_scene *scene)
{
	t_comps	computations;
	t_x		*xs;
	
	
	t_color	final_color;

	// Calculate world coordinates for the pixel
	params->world_position.x = -params->half_wall + params->pixel_size * x;
	params->world_position.y = params->half_wall - params->pixel_size * y;
	params->world_position.z = params->wall_z;
	params->world_position.w = 1.0; // It's a point

	// Calculate the ray direction from origin to the world position
	params->ray.direction = normalize_tuple(subtract_tuples(params->world_position, params->ray.origin));

	// Find intersections with the sphere
	xs = intersect(&params->ray, scene->objects);
	computations.hit = hit(xs); // Find the closest hit
	if (computations.hit && computations.hit->is_hit) // Check if hit is valid
	{
		// Calculate intersection point, eye vector, and normal vector
		computations.point = position(params->ray, computations.hit->t);
		computations.eyev = negate_tuple(params->ray.direction);
		computations.normalv = normal_at_sphere(scene->objects, computations.point); // Pass sphere object

		final_color = lighting(scene->objects->material, scene->light, computations.point, computations.eyev, computations.normalv, scene->ambient_light, false);

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
