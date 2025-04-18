#include "../../include/minirt.h"

/**
 * @brief Intersects a ray with all objects in the scene.
 * 
 * @param scene Pointer to the scene structure.
 * @param ray Pointer to the ray structure.
 * 
 * @return A linked list of intersection points (t_x) with the objects in the scene.
 * 
 * This function iterates through all objects in the scene and checks for intersections
 * with the given ray. It creates a linked list of intersection points (t_x) for each
 * object that the ray intersects with. The function returns the head of the linked list.
 * If no intersections are found, the list will be empty.
 */
t_x *intersect_world(t_data *data, t_ray *ray)
{
	t_x			*xs_list;
	t_x			*xs;
	t_object	*object;

	xs_list = NULL;
	object = data->scene->objects;
	while (object)
	{
		xs = intersect(data, ray, object);
		if (xs && !compare_doubles(xs->t, 0))
			add_intersection_node(&xs_list, xs);
		object = object->next;
	}
	return (xs_list);
}
