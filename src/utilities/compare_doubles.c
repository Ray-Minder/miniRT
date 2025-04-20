#include "../../include/minirt.h"

/**
 * @brief Compares two double values with a small epsilon value
 * 		to account for floating point precision.
 * 
 * @param a The first double value to compare.
 * @param b The second double value to compare.
 * 
 * @return true if the two values are considered equal, false otherwise.
 * 
 * @note The EPSILON value is defined as 1e-6.
 */
bool compare_doubles(double a, double b)
{
	if (a - b < EPSILON && a - b > -EPSILON)
		return (true);
	return (false);
}
