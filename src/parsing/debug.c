#include "../../include/scene.h"
#include "../../include/parser.h"

void	print_objects(t_object *object_list)
{
	while (object_list)
	{
		printf("position: %f, %f, %f\n", object_list->position.x, object_list->position.y, object_list->position.z);
		printf("diameter: %f\n", object_list->diameter);
		printf("color: %d, %d, %d\n\n\n", object_list->color.r, object_list->color.g, object_list->color.b);
		object_list = object_list->next;
	}
}
