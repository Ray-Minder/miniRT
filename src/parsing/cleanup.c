# include "../../include/minirt.h"

void	cleanup(t_scene *scene)
{
	t_object	*object;
	t_object	*next;

	object = scene->objects;
	while (object)
	{
		free(object->transform);
		next = object->next;
		free(object);
		object = next;
	}
	scene->objects = NULL;
}
