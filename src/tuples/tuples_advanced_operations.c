#include "../../include/minirt.h"

//	=== Function Declarations ===

double	tuple_magnitude(t_tuple t);
t_tuple	normalize_tuple(t_tuple t);
double	dot_product(t_tuple a, t_tuple b);
t_tuple	cross_product(t_tuple a, t_tuple b);

//	=== Function Definitions ===

/**
 * @brief Calculates the magnitude of a tuple.
 *
 * This function computes the magnitude (or length) of a tuple by taking
 * the square root of the sum of the squares of its components.
 *
 * @param t The tuple whose magnitude is to be calculated.
 *
 * @return The magnitude of the tuple.
 */
double	tuple_magnitude(t_tuple t)
{
	double	magnitude;

	magnitude = sqrt(pow(t.x, 2) + pow(t.y, 2) + pow(t.z, 2) + pow(t.w, 2));
	return (magnitude);
}

/**
 * @brief Normalizes a tuple.
 *
 * This function normalizes a tuple by dividing each of its components
 * by its magnitude, resulting in a tuple of unit length.
 *
 * @param t The tuple to be normalized.
 *
 * @return The normalized tuple.
 */
t_tuple	normalize_tuple(t_tuple t)
{
	t_tuple	normalized_tuple;
	double	magnitude;

	magnitude = tuple_magnitude(t);
	normalized_tuple.x = t.x / magnitude;
	normalized_tuple.y = t.y / magnitude;
	normalized_tuple.z = t.z / magnitude;
	normalized_tuple.w = t.w / magnitude;
	return (normalized_tuple);
}

/**
 * @brief Computes the dot product of two tuples.
 *
 * This function calculates the dot product of two tuples by summing
 * the products of their corresponding components. If the result is
 * very close to zero, it is set to zero.
 *
 * @param a The first tuple.
 * @param b The second tuple.
 *
 * @return The dot product of the two tuples.
 */
double	dot_product(t_tuple a, t_tuple b)
{
	double	result;

	result = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	if (compare_doubles(result, 0.0000))
		result = 0;
	return (result);
}

/**
 * @brief Computes the cross product of two tuples.
 *
 * This function calculates the cross product of two tuples, which
 * results in a new tuple that is perpendicular to both input tuples.
 * The w component is set to 0.0 as the cross product is only defined
 * for vectors (tuples with w = 0.0).
 *
 * @param a The first tuple.
 * @param b The second tuple.
 *
 * @return The cross product of the two tuples as a new tuple.
 */
t_tuple	cross_product(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result = vector(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
	return (result);
}
