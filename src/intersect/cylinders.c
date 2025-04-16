#include "../../include/minirt.h"

t_x *cylinder_intersect(t_ray *ray, t_object *cylinder)
{
	t_x		*xs;

	if (cylinder == NULL || ray == NULL)
		return (NULL);
	xs = new_intersection_node();
	if (xs == NULL)
		return (NULL);
	xs->hit = false;
	return (xs);
}