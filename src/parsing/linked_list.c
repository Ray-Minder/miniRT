#include "../../include/scene.h"
#include "../../include/parser.h"
#include <stdlib.h>

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
