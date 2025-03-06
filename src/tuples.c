#include "../include/tuples.h"

t_tuple tuple(double x, double y, double z, double w)
{
	t_tuple tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	if (w == 0 || w == 1)
		tuple.w = w;
	else
	{
		// printf("The tuple is neither a vector nor a point.\n");
		// tuple.w = -1;
		tuple.w = w; //Later remove this line and uncomment the above lines.
	}
	return (tuple);
}

void print_tuple(t_tuple tuple)
{
	printf("x: %f\n", tuple.x);
	printf("y: %f\n", tuple.y);
	printf("z: %f\n", tuple.z);
	printf("w: %f\n", tuple.w);
}

t_tuple point(double x, double y, double z)
{
	t_tuple tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 1;
	return (tuple);
}

t_tuple vector(double x, double y, double z)
{
	t_tuple tuple;

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

t_tuple subtract_tuples(t_tuple a, t_tuple b)
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

t_tuple negate_tuple(t_tuple t)
{
	t_tuple negated_tuple;

	negated_tuple.x = -t.x;
	negated_tuple.y = -t.y;
	negated_tuple.z = -t.z;
	negated_tuple.w = t.w; // This shouldn't be negated actually.
	return (negated_tuple);
}

t_tuple multiply_tuple_by_scalar(t_tuple t, double scalar)
{
	t_tuple result;

	result.x = t.x * scalar;
	result.y = t.y * scalar;
	result.z = t.z * scalar;
	result.w = t.w;
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
	normalized_tuple.w = t.w; //This one I believe shouldn't be normalized.
	return (normalized_tuple);
}

double dot_product(t_tuple a, t_tuple b)
{
	double result;

	result = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
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
