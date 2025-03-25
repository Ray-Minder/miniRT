#include "../../include/tuples.h"

//	=== Function Declarations ===

void 	print_tuple(t_tuple tuple);
bool	compare_tuples(t_tuple a, t_tuple b);

//	=== Function Definitions ===

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

bool	compare_tuples(t_tuple a, t_tuple b)
{
	if (a.x != b.x
		|| a.y != b.y
		|| a.z != b.z
		|| a.w != b.w)
		return (false);
	return (true);
}
