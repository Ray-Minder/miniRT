/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_intersect.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:12:09 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:12:10 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_x	*create_node_pair(t_object *object)
{
	t_x	*xs;

	xs = new_intersection_node();
	if (!xs)
		return (NULL);
	xs->next = new_intersection_node();
	if (!xs->next)
	{
		free_intersections_list(&xs);
		return (NULL);
	}
	xs->object = object;
	xs->next->object = object;
	return (xs);
}

static void	calculate_intersects(t_ray *ray, t_x *xs)
{
	const t_tuple	sphere_ray = subtract_tuples(ray->origin, point(0, 0, 0));
	const double	a = dot_product(ray->dir, ray->dir);
	const double	b = 2 * dot_product(ray->dir, sphere_ray);
	const double	c = dot_product(sphere_ray, sphere_ray) - 1;
	const double	discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
		return ;
	xs->t = (-b - sqrt(discriminant)) / (2 * a);
	xs->is_hit = true;
	xs->next->t = (-b + sqrt(discriminant)) / (2 * a);
	xs->next->is_hit = true;
}

t_x	*sphere_intersect(t_ray *ray, t_object *sphere)
{
	t_x	*xs;

	xs = create_node_pair(sphere);
	if (!xs)
		return (NULL);
	calculate_intersects(ray, xs);
	return (xs);
}
