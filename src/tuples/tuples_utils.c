#include "../../include/minirt.h"

//	=== Function Declarations ===

void 	print_tuple(t_tuple tuple);
bool	compare_tuples(t_tuple a, t_tuple b);
t_color	tuple_to_color(t_tuple tuple);
t_tuple	color_to_tuple(t_color color);

//	=== Function Definitions ===

/**
 * @brief Prints the details of a tuple.
 *
 * This function prints whether the tuple represents a vector or a point
 * based on the value of the w component. It then prints the values of
 * all components (x, y, z, w) of the tuple.
 *
 * @param tuple The tuple to be printed.
 */
void print_tuple(t_tuple tuple)
{
	if (tuple.w == 0.0)
		printf("The tuple is a vector.\n");
	else if (tuple.w == 1.0)
		printf("The tuple is a point.\n");
	else
		printf("The tuple is neither a vector nor a point.\n");
	printf("x: %f\n", tuple.x);
	printf("y: %f\n", tuple.y);
	printf("z: %f\n", tuple.z);
	printf("w: %f\n", tuple.w);
}

/**
 * @brief Compares two tuples for equality.
 *
 * This function checks if two tuples are equal by comparing their
 * respective components (x, y, z, w). If all components are equal,
 * the function returns true; otherwise, it returns false.
 *
 * @param a The first tuple to compare.
 * @param b The second tuple to compare.
 *
 * @return True if the tuples are equal, false otherwise.
 */
bool	compare_tuples(t_tuple a, t_tuple b)
{
	if (a.x != b.x
		|| a.y != b.y
		|| a.z != b.z
		|| a.w != b.w)
		return (false);
	return (true);
}

/**
 * @brief Converts a tuple to a color.
 *
 * This function converts a tuple to a color by extracting the
 * red, green, and blue components from the tuple. The w component
 * is ignored in this conversion.
 *
 * @param tuple The tuple to be converted.
 *
 * @return The resulting color.
 */
t_color	tuple_to_color(t_tuple tuple)
{
	t_color	color;

	color.r = tuple.x;
	color.g = tuple.y;
	color.b = tuple.z;
	return (color);
}

/**
 * @brief Converts a color to a tuple.
 *
 * This function converts a color to a tuple by setting the x, y,
 * and z components of the tuple to the red, green, and blue
 * components of the color, respectively. The w component is set
 * to 0.0.
 *
 * @param color The color to be converted.
 *
 * @return The resulting tuple.
 */
t_tuple	color_to_tuple(t_color color)
{
	t_tuple	tuple;

	tuple.x = color.r;
	tuple.y = color.g;
	tuple.z = color.b;
	tuple.w = 0.0;
	return (tuple);
}
