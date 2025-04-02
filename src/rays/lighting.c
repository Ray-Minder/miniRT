#include "../../include/minirt.h"

// t_color	ambient_lighting(t_ambient_light ambient_light, t_color object_color)
// {
// 	t_color	ambient;

// 	ambient = multiply_color_by_scalar(ambient_light.color, ambient_light.brightness);

// 	ambient = hadamard_product(ambient, object_color);
// 	return (ambient);
// }

// t_color	diffuse_lighting(t_light light, t_tuple normal, t_tuple position, t_color object_color)
// {
// 	t_color	diffuse;
// 	// t_color scaled_color;
// 	t_tuple	light_direction;
// 	double	light_dot_normal;
	
// 	light_direction = normalize_tuple(subtract_tuples(light.position, position));
// 	light_dot_normal = dot_product(normal, light_direction);
// 	if (light_dot_normal < 0)
// 		diffuse = color(0, 0, 0);
// 	else
// 	{
// 		diffuse = multiply_color_by_scalar(object_color, light.brightness * light_dot_normal);
// 		diffuse = hadamard_product(diffuse, light.color);
// 	}

// 	return (diffuse);
// }

t_color calculate_ambient_lighting(t_ambient_light ambient_light, t_material material)
{
	t_color effective_ambient_light;
	t_color material_ambient_response;

	// 1. Calculate the effective ambient light (color * brightness)
	effective_ambient_light = multiply_color_by_scalar(ambient_light.color,
			ambient_light.brightness);

	// 2. Calculate the material's base color scaled by its ambient coefficient
	//    Note: Some interpretations multiply effective_ambient_light by material.color directly.
	//    The book often does effective_color = material.color * light.color first.
	//    Let's follow: material_base * ambient_coeff
	material_ambient_response = multiply_color_by_scalar(material.color,
			material.ambient);

	// 3. Combine them using Hadamard product
	return (hadamard_product(effective_ambient_light,
			material_ambient_response));
	// Alternative approach from the book (often Chapter 6):
	// return multiply_color_by_scalar(material.color, material.ambient);
	// This simpler version assumes ambient light is white (1,1,1) and its
	// intensity is folded into material.ambient. MiniRT requires ambient light
	// color and ratio, so the first approach is better suited. Let's stick
    // with the first, more explicit calculation.
}



t_color	calculate_diffuse_lighting(t_light light, t_material material, t_color effective_color, double light_dot_normal)
{
	t_color diffuse_color;

	// Calculate diffuse contribution
	diffuse_color = multiply_color_by_scalar(effective_color,
			material.diffuse * light_dot_normal * light.brightness);
			// Note: Brightness multiplication moved here for consistency
            // with the original 'lighting' function's approach.

	return (diffuse_color);
}

t_color	calculate_specular_lighting(t_light light, t_material material,	double reflect_dot_eye)
{
	double	factor;
	t_color	specular_color;

	// Calculate the specular factor
	factor = pow(reflect_dot_eye, material.shininess);

	// Calculate specular contribution
	specular_color = multiply_color_by_scalar(light.color,
			material.specular * factor * light.brightness);
            // Note: Brightness multiplication included here.

	return (specular_color);
}

t_color lighting(t_material material, t_light light, t_tuple point,
				 t_tuple eyev, t_tuple normalv,
				 t_ambient_light ambient_light, bool in_shadow)
{
	t_color effective_color; // Combination of material and light colors
	t_tuple lightv;			 // Vector from point to light source
	double light_dot_normal;
	t_color ambient_c;
	t_color diffuse_c;
	t_color specular_c;
	t_color final_color;

	// 1. Calculate ambient contribution (always present, regardless of shadow)
	ambient_c = calculate_ambient_lighting(ambient_light, material);

	// Combine material color and light color ONCE
	// (used for both diffuse and potentially specular if not handled inside)
	effective_color = hadamard_product(material.color, light.color);

	// Calculate the direction vector from the point to the light source
	lightv = normalize_tuple(subtract_tuples(light.position, point));

	// Calculate the cosine of the angle between the light vector and the normal vector.
	light_dot_normal = dot_product(lightv, normalv);

	// Initialize diffuse and specular to black
	diffuse_c = color(0, 0, 0);
	specular_c = color(0, 0, 0);

	// Check if the point is in shadow OR if the light strikes the back side
	if (in_shadow == false && light_dot_normal >= 0)
	{
		// 2. Calculate diffuse contribution
		diffuse_c = calculate_diffuse_lighting(light, material,
												   effective_color, light_dot_normal);

		// 3. Calculate specular contribution
		t_tuple reflectv;
		double reflect_dot_eye;

		// Find the reflection of the light vector around the normal
		reflectv = reflect(negate_tuple(lightv), normalv);
		// Calculate the cosine of the angle between the reflection vector and the eye vector.
		reflect_dot_eye = dot_product(reflectv, eyev);

		if (reflect_dot_eye > 0) // Specular highlight is visible
		{
			specular_c = calculate_specular_lighting(light, material,
														 reflect_dot_eye);
		}
	}

	// 4. Add all contributions
	final_color = add_colors(ambient_c, diffuse_c);
	final_color = add_colors(final_color, specular_c);

	return (final_color);
}

// t_color	lighting(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv)
// {
// 	t_color	effective_color;
// 	t_tuple	lightv;
// 	double	light_dot_normal;
// 	t_color	diffuse = color(0, 0, 0);
// 	t_color	specular = color(0, 0, 0);
// 	t_tuple	reflectv;
// 	double	reflect_dot_eye;
// 	double	factor;

// 	effective_color = hadamard_product(material.color, light.color);

// 	lightv = normalize_tuple(subtract_tuples(light.position, point));
// 	light_dot_normal = dot_product(lightv, normalv);
	
// 	if (light_dot_normal < 0)
// 	{
// 		diffuse = color(0, 0, 0);
// 		specular = color(0, 0, 0);
// 	}
// 	else
// 	{
// 		diffuse = multiply_color_by_scalar(effective_color, material.diffuse);
// 		diffuse = multiply_color_by_scalar(diffuse, light_dot_normal);
// 		diffuse = multiply_color_by_scalar(diffuse, light.brightness);

// 		reflectv = reflect(negate_tuple(lightv), normalv);
// 		reflect_dot_eye = dot_product(reflectv, eyev);
// 		if (reflect_dot_eye <= 0)
// 		{
// 			specular = color(0, 0, 0);
// 		}
// 		else
// 		{
// 			factor = pow(reflect_dot_eye, material.shininess);

// 			specular = multiply_color_by_scalar(specular, material.specular);
// 			specular = multiply_color_by_scalar(specular, factor);
// 		}
// 	}

// 	return (add_colors(diffuse, specular));
// }
