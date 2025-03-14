#include "../../include/tuples.h"
#include "../../include/utilities.h"

//	=== Function Declarations ===

double	tuple_magnitude(t_tuple t);
t_tuple	normalize_tuple(t_tuple t);
double	dot_product(t_tuple a, t_tuple b);
t_tuple	cross_product(t_tuple a, t_tuple b);

//	=== Function Definitions ===

double tuple_magnitude(t_tuple t)
{
	double magnitude;

	magnitude = sqrt(pow(t.x, 2) + pow(t.y, 2) + pow(t.z, 2) + pow(t.w, 2));
	return (magnitude);
}

t_tuple normalize_tuple(t_tuple t)
{
	t_tuple normalized_tuple;
	double magnitude;

	magnitude = tuple_magnitude(t);
	normalized_tuple.x = t.x / magnitude;
	normalized_tuple.y = t.y / magnitude;
	normalized_tuple.z = t.z / magnitude;
	normalized_tuple.w = t.w / magnitude;
	return (normalized_tuple);
}

double dot_product(t_tuple a, t_tuple b)
{
	double result;

	result = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	if (compare_doubles(result, 0.0000))
		result = 0;
	return (result);
}

t_tuple cross_product(t_tuple a, t_tuple b)
{
	t_tuple result;

	result = vector(a.y * b.z - a.z * b.y,
					a.z * b.x - a.x * b.z,
					a.x * b.y - a.y * b.x);
	return (result);
}
