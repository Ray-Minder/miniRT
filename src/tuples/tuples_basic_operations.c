#include "../../include/minirt.h"

//	=== Function Declarations ===

t_tuple	add_tuples(t_tuple a, t_tuple b);
t_tuple	subtract_tuples(t_tuple a, t_tuple b);
t_tuple	negate_tuple(t_tuple t);
t_tuple	multiply_tuple_by_scalar(t_tuple t, double scalar);
t_tuple	divide_tuple_by_scalar(t_tuple t, double scalar);

//	=== Function Definitions ===

/**
 * @brief Adds two tuples.
 * 
 * This function takes two tuples and returns a new tuple where each
 * component is the sum of the corresponding components of the input tuples.
 *
 * @param a The first tuple.
 * @param b The second tuple.
 *
 * @return A tuple where each component is the sum of the corresponding
 *         components of the input tuples.
 */
t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return (result);
}

/**
 * @brief Subtracts the second tuple from the first.
 *
 * This function takes two tuples and returns a new tuple where each
 * component is the difference of the corresponding components 
 * of the input tuples.
 *
 * @param a The first tuple.
 * @param b The second tuple.
 *
 * @return A tuple where each component is the difference of the corresponding
 *         components of the input tuples.
 */
t_tuple	subtract_tuples(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	return (result);
}

/**
 * @brief Negates a tuple.
 *
 * This function takes a tuple and returns a new tuple where each
 * component is the negation of the corresponding component of the input tuple.
 *
 * @param t The tuple to negate.
 *
 * @return A tuple where each component is the negation of the corresponding
 *         component of the input tuple.
 */
t_tuple	negate_tuple(t_tuple t)
{
	t_tuple	zero;
	t_tuple	negated_tuple;

	zero = tuple(0.0, 0.0, 0.0, 0.0);
	negated_tuple = subtract_tuples(zero, t);
	return (negated_tuple);
}

/**
 * @brief Multiplies a tuple by a scalar.
 *
 * This function takes a tuple and a scalar value, and returns a new tuple
 * where each component is the product of the corresponding component of the
 * input tuple and the scalar.
 *
 * @param t The tuple to multiply.
 * @param scalar The scalar value to multiply by.
 *
 * @return A tuple where each component is the product of the corresponding
 *         component of the input tuple and the scalar.
 */
t_tuple	multiply_tuple_by_scalar(t_tuple t, double scalar)
{
	t_tuple	result;

	result.x = t.x * scalar;
	result.y = t.y * scalar;
	result.z = t.z * scalar;
	result.w = t.w * scalar;
	return (result);
}

/**
 * @brief Divides a tuple by a scalar.
 *
 * This function takes a tuple and a scalar value, and returns a new tuple
 * where each component is the quotient of the corresponding component of the
 * input tuple and the scalar. The w component remains unchanged.
 *
 * @param t The tuple to divide.
 * @param scalar The scalar value to divide by.
 *
 * @return A tuple where each component is the quotient of the corresponding
 *         component of the input tuple and the scalar,
 * 		   except for the w component.
 */
t_tuple	divide_tuple_by_scalar(t_tuple t, double scalar)
{
	t_tuple	result;

	result.x = t.x / scalar;
	result.y = t.y / scalar;
	result.z = t.z / scalar;
	result.w = t.w;
	return (result);
}
