#include "../include/tuples.h"

t_tuple	tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	// if (w == 0 || w == 1)
	// 	tuple.w = w;
	// else
	// {
	// 	// printf("The tuple is neither a vector nor a point.\n");
	// 	tuple.w = -1;
	// }
	return (tuple);
}

t_tuple	point(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 1;
	return (tuple);
}

t_tuple	vector(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 0;
	return (tuple);
}

t_tuple add_tuples(t_tuple a, t_tuple b)
{
	t_tuple result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	if (result.w != 0 && result.w != 1)
	{
		// printf("Error adding tuples!\n"); //Later format the error messages better.
		// printf("The resulting tuple is neither a point nor a vector.\n");
	}
	return (result);
}

t_tuple	subtract_tuples(t_tuple a, t_tuple b)
{
	t_tuple result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	if (result.w != 0 && result.w != 1)
	{
		// printf("Error subtracting tuples!\n"); //Later format the error messages better.
		// printf("The resulting tuple is neither a point nor a vector.\n");
	}
	return (result);
}

t_tuple	negate_tuple(t_tuple t)
{
	t_tuple negated_tuple;

	negated_tuple.x = -t.x;
	negated_tuple.y = -t.y;
	negated_tuple.z = -t.z;
	negated_tuple.w = t.w; //This shouldn't be negated actually.
	return (negated_tuple);
}

void	print_tuple(t_tuple tuple)
{
	printf("x: %f\n", tuple.x);
	printf("y: %f\n", tuple.y);
	printf("z: %f\n", tuple.z);
	printf("w: %f\n", tuple.w);
}
