#include "../../include/minirt.h"


t_tuple reflect(t_tuple in, t_tuple normal);

t_tuple reflect(t_tuple in, t_tuple normal)
{
	t_tuple reflected;

	reflected = subtract_tuples(in, multiply_tuple_by_scalar(normal, 2 * dot_product(in, normal)));
	return (reflected);
}
