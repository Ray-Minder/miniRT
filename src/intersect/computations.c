#include "../../include/minirt.h"

/**
 * @brief Prepares the computations for shading calculations.
 * 
 * @param hit Pointer to the intersection data.
 * @param ray Pointer to the ray structure.
 * 
 * @return A pointer to a t_comps structure containing the computed values.
 * 
 * This function calculates the intersection point, eye vector, normal vector,
 * and whether the intersection point is inside the object.
 * It also computes the over_point, which is slightly offset from the intersection point
 * to avoid floating-point inaccuracies.
 */
t_comps	*prepare_computations(t_x *hit, t_ray *ray)
{
	t_comps	*comps;

	comps = ft_calloc(1, sizeof(t_comps));
	if (!comps)
	{
		printf("Failed to allocate memory for t_comps\n");
		return (NULL);
	}
	comps->hit = hit;
	comps->object = hit->object;
	comps->point = position(*ray, hit->t);
	comps->normalv = normal_at(comps->object, comps->point);
	comps->inside = false;
	if (dot_product(comps->normalv, ray->direction) > 0)
	{
		comps->inside = true;
		comps->normalv = negate_tuple(comps->normalv);
	}
	comps->over_point = add_tuples(comps->point, multiply_tuple_by_scalar(comps->normalv, EPSILON));
	return (comps);
}
