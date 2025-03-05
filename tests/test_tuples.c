#include "tuples.h"
#include <assert.h>


void test_tuple_creation()
{
    t_tuple t1 = tuple(1.0, 2.0, 3.0, 1.0);
	t_tuple t2 = tuple(1.0, 2.0, 3.0, 4.0);
	t_tuple	p1 = point(1.0, 2.0, 3.0);
	t_tuple	v1 = vector(1.0, 2.0, 3.0);

    assert(t1.x == 1.0);
    assert(t1.y == 2.0);
    assert(t1.z == 3.0);
    assert(t1.w == 1.0);

	assert(t2.x == 1.0);
    assert(t2.y == 2.0);
    assert(t2.z == 3.0);
    assert(t2.w == -1.0);

	assert(p1.x == 1.0);
    assert(p1.y == 2.0);
    assert(p1.z == 3.0);
    assert(p1.w == 1.0);

	assert(v1.x == 1.0);
    assert(v1.y == 2.0);
    assert(v1.z == 3.0);
    assert(v1.w == 0.0);
}

void test_print_tuple()
{
    t_tuple t = tuple(1.0, 2.0, 3.0, 4.0);
    print_tuple(t);
}

int main()
{
    test_tuple_creation();
	test_print_tuple();
    printf("All tests passed!\n");
    return (0);
}
