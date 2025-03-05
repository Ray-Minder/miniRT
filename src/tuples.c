#include "../include/tuples.h"

t_tuple	tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;

	return (tuple);
}

void	print_tuple(t_tuple tuple)
{
	printf("x: %f\n", tuple.x);
	printf("y: %f\n", tuple.y);
	printf("z: %f\n", tuple.z);
	printf("w: %f\n", tuple.w);
}
