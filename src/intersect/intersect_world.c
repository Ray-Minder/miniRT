#include "../../include/minirt.h"

t_x *intersect_world(t_scene *scene, t_ray *ray)
{
	t_x			*xs_list;
	t_x			*xs;
	t_object	*object;

	xs_list = NULL;
	object = scene->objects;
	while (object)
	{
		xs = intersect(ray, object);
		// if (object->type == PLANE)
		// 	printf("plane t: %f\n", xs->t);
		if (xs && !compare_doubles(xs->t, 0))
			add_intersection_node(&xs_list, xs);
		object = object->next;
	}
	return (xs_list);
}
