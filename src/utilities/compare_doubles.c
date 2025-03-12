#include "../../include/constants.h"
#include <stdbool.h>

bool compare_doubles(double a, double b)
{
	if (a - b < EPSILON && a - b > -EPSILON)
		return (true);
	return (false);
}
