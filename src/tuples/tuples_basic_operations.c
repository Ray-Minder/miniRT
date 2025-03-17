#include "../../include/tuples.h"

//	=== Function Declarations ===

t_tuple	add_tuples(t_tuple a, t_tuple b);
t_tuple	subtract_tuples(t_tuple a, t_tuple b);
t_tuple	negate_tuple(t_tuple t);
t_tuple	multiply_tuple_by_scalar(t_tuple t, double scalar);
t_tuple	divide_tuple_by_scalar(t_tuple t, double scalar);

//	=== Function Definitions ===

t_tuple add_tuples(t_tuple a, t_tuple b)
{
	t_tuple result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return (result);
}

t_tuple subtract_tuples(t_tuple a, t_tuple b)
{
	t_tuple result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	return (result);
}

t_tuple negate_tuple(t_tuple t)
{
	t_tuple	zero;
	t_tuple negated_tuple;

	zero = tuple(0.0, 0.0, 0.0, 0.0);
	negated_tuple = subtract_tuples(zero, t);
	return (negated_tuple);
}

t_tuple multiply_tuple_by_scalar(t_tuple t, double scalar)
{
	t_tuple result;

	result.x = t.x * scalar;
	result.y = t.y * scalar;
	result.z = t.z * scalar;
	result.w = t.w * scalar;
	return (result);
}

t_tuple divide_tuple_by_scalar(t_tuple t, double scalar)
{
	t_tuple result;

	result.x = t.x / scalar;
	result.y = t.y / scalar;
	result.z = t.z / scalar;
	result.w = t.w;
	return (result);
}
