#include "tuples.h"
#include <assert.h>


void test_tuple_creation() {
    t_tuple t = tuple(1.0, 2.0, 3.0, 4.0);
    assert(t.x == 1.0);
    assert(t.y == 2.0);
    assert(t.z == 3.0);
    assert(t.w == 4.0);
}

void test_print_tuple() {
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
