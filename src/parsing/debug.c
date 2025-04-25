#include "../../include/minirt.h"

//	=== Function Declarations ===

void	print_light(t_light *light);
void	print_objects(t_object *object_list);

//	=== Function Definitions ===

void	print_light(t_light *light)
{
	if (!light)
		return ;
	printf("Light position: %f, %f, %f\n", light->position.x, light->position.y, light->position.z);
	printf("Light color: %f, %f, %f\n", light->color.r, light->color.g, light->color.b);
	printf("Light brightness: %f\n", light->brightness);
}

void	print_objects(t_object *object_list)
{
	while (object_list)
	{
		printf("Position: %f, %f, %f\n", object_list->pos.x, object_list->pos.y, object_list->pos.z);
		printf("Diameter: %f\n", object_list->diameter);
		printf("Color: %f, %f, %f\n", object_list->color.r, object_list->color.g, object_list->color.b);
		printf("Transform matrix: \n");
		print_matrix(object_list->transform);
		object_list = object_list->next;
	}
}
