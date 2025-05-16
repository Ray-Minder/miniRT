/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_world.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:11:54 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:11:55 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	proccess_object_intersections(
	t_data *data,
	t_object *object,
	t_ray *ray,
	t_x **xs_list)
{
	t_x	*xs;
	t_x	*next;

	xs = intersect(data, ray, object);
	if (!xs)
		print_clean_and_exit(data, MALLOC_FAIL, EXIT_FAILURE);
	while (xs)
	{
		next = xs->next;
		if (!compare_doubles(xs->t, 0.0))
		{
			add_intersection_node(xs_list, xs);
			break ;
		}
		free(xs);
		xs = next;
	}
}

t_x	*intersect_world(t_data *data, t_ray *ray)
{
	t_x			*xs_list;
	t_object	*object;

	xs_list = NULL;
	object = data->scene->objects;
	while (object)
	{
		proccess_object_intersections(data, object, ray, &xs_list);
		object = object->next;
	}
	return (xs_list);
}
