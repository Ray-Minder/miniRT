#include "../../include/parser.h"
#include "../../include/scene.h"
#include <stdlib.h>

t_object *get_last_object(t_object *object)
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
	t_object *ptr;

	ptr = (t_object *)malloc(sizeof(t_object));
	if (!ptr)
		return (NULL);
	ptr->next = NULL;
	return (ptr);
}

int add_new_object(t_scene *scene, t_object **new_object)
{
    t_object *last_object;

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

int parse_sphere(char **line, t_scene *scene)
{
	t_object *new_object;
	int error;

	error = add_new_object(scene, &new_object);
	if (error != SUCCESS)
		return (error);
	new_object->type = SPHERE;
	if (count_tokens(line) != 4)
		return (INVALID_ARG_COUNT);
	error = parse_tuple(line[1], &new_object->position);
	if (error != SUCCESS)
		return (error);
	error = parse_double(line[2], &new_object->diameter);
	if (error != SUCCESS)
		return (error);
	error = parse_color(line[3], &new_object->color);
	if (error != SUCCESS)
		return (error);
	return (SUCCESS);
}

int parse_plane(char **line, t_scene *scene)
{
	t_object *new_object;
	int error;

	error = add_new_object(scene, &new_object);
	if (error != SUCCESS)
		return (error);
	new_object->type = PLANE;
	if (count_tokens(line) != 4)
		return (INVALID_ARG_COUNT);
	error = parse_tuple(line[1], &new_object->position);
	if (error != SUCCESS)
		return (error);
	error = parse_tuple(line[2], &new_object->transform);
	if (error != SUCCESS)
		return (error);
	error = parse_color(line[3], &new_object->color);
	if (error != SUCCESS)
		return (error);
	return (SUCCESS);
}

int parse_cylinder(char **line, t_scene *scene)
{
	t_object *new_object;
	int error;

	error = add_new_object(scene, &new_object);
	if (error != SUCCESS)
		return (error);
	new_object->type = CYLINDER;
	if (count_tokens(line) != 6)
		return (INVALID_ARG_COUNT);
	error = parse_tuple(line[1], &new_object->position);
	if (error != SUCCESS)
		return (error);
	error = parse_tuple(line[2], &new_object->transform);
	if (error != SUCCESS)
		return (error);
	error = parse_double(line[3], &new_object->diameter);
	if (error != SUCCESS)
		return (error);
	error = parse_double(line[4], &new_object->height);
	if (error != SUCCESS)
		return (error);
	error = parse_color(line[5], &new_object->color);
	if (error != SUCCESS)
		return (error);
	return (SUCCESS);
}

void print_objects(t_object *object_list)
{
	while (object_list)
	{
		printf("position: %f, %f, %f\n", object_list->position.x, object_list->position.y, object_list->position.z);
		printf("diameter: %f\n", object_list->diameter);
		printf("color: %d, %d, %d\n\n\n", object_list->color.r, object_list->color.g, object_list->color.b);
		object_list = object_list->next;
	}
}