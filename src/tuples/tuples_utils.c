#include "../../include/minirt.h"

//	=== Function Declarations ===

void 	print_tuple(t_tuple tuple);
bool	compare_tuples(t_tuple a, t_tuple b);

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
