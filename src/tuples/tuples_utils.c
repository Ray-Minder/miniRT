#include "../include/tuples.h"

//	=== Function Declarations ===

void print_tuple(t_tuple tuple);

//	=== Function Definitions ===

void print_tuple(t_tuple tuple)
{
	if (tuple.w == 1.0)
		printf("The tuple is a point.\n");
	else
		printf("The Tuple is a vector.\n");
	printf("x: %f\n", tuple.x);
	printf("y: %f\n", tuple.y);
	printf("z: %f\n", tuple.z);
}
