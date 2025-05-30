/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:13:03 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:13:04 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

t_object	*get_last_object(t_object *object);
t_object	*create_object(void);
int			add_new_object(t_scene *scene, t_object **new_object);

//	=== Function Definitions ===

t_object	*get_last_object(t_object *object)
{
	if (!object)
		return (NULL);
	while (object->next)
	{
		object = object->next;
	}
	return (object);
}

t_object	*create_object(void)
{
	t_object	*ptr;

	ptr = (t_object *)malloc(sizeof(t_object));
	if (!ptr)
		return (NULL);
	ptr->diameter = 0;
	ptr->height = 0;
	ptr->color.b = 0;
	ptr->color.g = 0;
	ptr->color.r = 0;
	ptr->pos = point(0, 0, 0);
	ptr->dir = vector(0, 0, 0);
	ptr->transform = NULL;
	ptr->inv_transform = NULL;
	ptr->inv_transpose = NULL;
	ptr->next = NULL;
	return (ptr);
}

int	add_new_object(t_scene *scene, t_object **new_object)
{
	t_object	*last_object;

	*new_object = create_object();
	if (!*new_object)
		return (MALLOC_FAIL);
	last_object = get_last_object(scene->objects);
	if (!last_object)
		scene->objects = *new_object;
	else
		last_object->next = *new_object;
	return (SUCCESS);
}
