#include "../../include/minirt.h"

//	=== Function Declarations ===

t_tuple	tuple(double x, double y, double z, double w);
t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);

//	=== Function Definitions ===

/**
 * @brief Creates and initializes a tuple with the given values.
 * 
 * A tuple is an ordered set of values.
 * 
 * @param x The value to be assigned to the x component of the tuple.
 * @param y The value to be assigned to the y component of the tuple.
 * @param z The value to be assigned to the z component of the tuple.
 * @param w The value to be assigned to the w component of the tuple.
 * 
 * @return A tuple structure with the initialized values.
 */
t_tuple	tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

/**
 * @brief Creates a tuple representing a point.
 *
 * This function creates a tuple with the given x, y, and z coordinates
 * and sets the w component to 1.0, which is a common convention for
 * representing a point.
 *
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 * @param z The z-coordinate of the point.
 *
 * @return A tuple structure representing a point with w = 1.0.
 */
t_tuple	point(double x, double y, double z)
{
	return (tuple(x, y, z, 1.0));
}

/**
 * @brief Creates a tuple representing a vector.
 *
 * This function creates a tuple with the given x, y, and z components
 * and sets the w component to 0.0, which is a common convention for
 * representing a vector.
 *
 * @param x The x-component of the vector.
 * @param y The y-component of the vector.
 * @param z The z-component of the vector.
 *
 * @return A tuple structure representing a vector with w = 0.0.
 */
t_tuple	vector(double x, double y, double z)
{
	return (tuple(x, y, z, 0.0));
}
