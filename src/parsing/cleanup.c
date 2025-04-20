# include "../../include/minirt.h"

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
		next = object->next;
		free(object);
		object = next;
	}
	scene->objects = NULL;
}
