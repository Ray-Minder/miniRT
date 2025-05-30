/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_caps.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:35:22 by eandela       #+#    #+#                 */
/*   Updated: 2025/05/01 13:26:10 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

bool	check_cap(t_ray *ray, double t)
{
	double	x;
	double	z;

	x = ray->origin.x + t * ray->dir.x;
	z = ray->origin.z + t * ray->dir.z;
	if (x * x + z * z <= 1.0)
		return (true);
	return (false);
}

t_x	*intersect_caps(t_object *cylinder, t_ray *ray)
{
	double	t0;
	double	t1;
	t_x		*caps;

	if (compare_doubles(ray->dir.y, 0.0))
		return (NULL);
	caps = create_node_pair(cylinder);
	if (caps == NULL)
		return (NULL);
	t0 = (-(cylinder->height / 2) - ray->origin.y) / ray->dir.y;
	if (check_cap(ray, t0))
	{
		caps->t = t0;
		caps->is_hit = true;
	}
	t1 = ((cylinder->height / 2) - ray->origin.y) / ray->dir.y;
	if (check_cap(ray, t1))
	{
		caps->next->t = t1;
		caps->next->is_hit = true;
	}
	return (caps);
}
