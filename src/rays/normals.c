#include "../../include/normals.h"
#include "../../include/scene.h"
#include "../../include/tuples.h"

t_tuple normal_at_sphere(t_object *object, t_tuple point)
{
	t_tuple	normal;

	if (object->type != SPHERE)
	{
		ft_putstr_fd("Error: normal_at_sphere() called on non-sphere object\n", 2);
		exit(EXIT_FAILURE);
	}
	normal = subtract_tuples(point, object->position);
	normal = normalize_tuple(normal);
	return (normal);
}
