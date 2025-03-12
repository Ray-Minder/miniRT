#include "../../include/tuples.h"

//	=== Function Declarations ===

t_tuple tuple(double x, double y, double z, double w);
t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);

//	=== Function Definitions ===

t_tuple tuple(double x, double y, double z, double w)
{
	t_tuple tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

t_tuple point(double x, double y, double z)
{
	return (tuple(x, y, z, 1.0));
}

t_tuple vector(double x, double y, double z)
{
	return (tuple(x, y, z, 0.0));
}
