/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersections.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:12:06 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:12:07 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

t_x		*intersect(t_data *data, t_ray *ray, t_object *object);
t_x		*hit(t_data *data, t_x *xs_list);
t_x		*plane_intersect(t_ray *ray, t_object *plane);

//	=== Function Definitions ===

/**
 * @brief Intersects a ray with an object.
 * 
 * @param data Pointer to the data structure.
 * @param ray Pointer to the ray structure.
 * @param object Pointer to the object structure.
 * 
 * @return A linked list of intersection points (t_x) with the object.
 * 
 * This function uses the object's inverse transformation matrix
 * to bring the ray into the object's local space.
 * It then calculates the intersection points based on the object's type.
 * If no intersections are found, the list will be empty.
 */
t_x	*intersect(t_data *data, t_ray *ray, t_object *object)
{
	t_ray		transformed_ray;

	if (!ray || !object)
	{
		print_error_msg("Ray or object is NULL.\n");
		return (NULL);
	}
	transformed_ray = transform_ray(data, ray, object->inv_transform);
	if (object->type == SPHERE)
		return (sphere_intersect(&transformed_ray, object));
	if (object->type == PLANE)
		return (plane_intersect(&transformed_ray, object));
	if (object->type == CYLINDER)
		return (cylinder_intersect(&transformed_ray, object));
	return (NULL);
}

/**
 * @brief Finds the closest intersection point from a list of intersections.
 * 
 * @param data Pointer to the data structure.
 * @param xs_list Pointer to the linked list of intersection points (t_x).
 * 
 * @return A pointer to the closest intersection point (t_x)
 * or NULL if no intersections are found.
 * 
 * This function iterates through the list of intersection points
 * and finds the one with the smallest positive t value.
 * If no positive t values are found, it returns NULL.
 */
t_x	*hit(t_data *data, t_x *xs_list)
{
	t_x	*lowest_hit;

	if (!xs_list)
		return (NULL);
	lowest_hit = NULL;
	lowest_hit = new_intersection_node();
	if (!lowest_hit)
		print_clean_and_exit(data, MALLOC_FAIL, EXIT_FAILURE);
	lowest_hit->t = INFINITY;
	while (xs_list != NULL)
	{
		if (xs_list->t > EPSILON && xs_list->t < lowest_hit->t)
		{
			lowest_hit->is_hit = true;
			lowest_hit->t = xs_list->t;
			lowest_hit->object = xs_list->object;
		}
		xs_list = xs_list->next;
	}
	if (lowest_hit->is_hit == false)
		return (free(lowest_hit), NULL);
	return (lowest_hit);
}

/**
 * @brief Intersects a ray with a plane.
 * 
 * @param ray Pointer to the ray structure.
 * @param plane Pointer to the plane object.
 * 
 * @return A linked list of intersection points (t_x) with the plane.
 * 
 * This function calculates the intersection point between the ray and the plane.
 * If the ray is parallel to the plane,
 * it returns an intersection point at t = 0.
 */
t_x	*plane_intersect(t_ray *ray, t_object *plane)
{
	t_x	*xs;

	xs = new_intersection_node();
	if (!xs)
		return (NULL);
	if (compare_doubles(ray->dir.y, 0.0))
		return (xs);
	xs->t = -ray->origin.y / ray->dir.y;
	xs->is_hit = true;
	xs->object = plane;
	return (xs);
}
