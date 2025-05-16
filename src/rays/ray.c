/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:06:46 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:06:47 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

t_ray	create_ray(t_tuple origin, t_tuple direction);
t_tuple	position(t_ray ray, double t);

//	=== Function Definitions ===

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = direction;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	return (add_tuples(ray.origin, multiply_tuple_by_scalar(ray.dir, t)));
}
