#include "../../include/minirt.h"

//	=== Function Declarations ===

void	cleanup(t_scene *scene);

//	=== Function Definitions ===

void	cleanup(t_scene *scene)
{
	t_object	*object;
	t_object	*next;

	object = scene->objects;
	while (object)
	{
		if (object->transform)
			free_matrix(&object->transform);
		if (object->inv_transform)
			free_matrix(&object->inv_transform);
		if (object->inv_transpose)
			free_matrix(&object->inv_transpose);
		next = object->next;
		free(object);
		object = next;
	}
	scene->objects = NULL;
}
