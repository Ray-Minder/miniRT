#include "../include/minirt.h"

void test_tuple_to_matrix()
{
	print_matrix(get_transform(vector(1, 0, 0), point(1, 1, 1)));
}
int main()
{
	test_tuple_to_matrix();
}
	