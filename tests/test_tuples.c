#include "tuples.h"
#include <assert.h>

void	test_tuple_creation()
{
    t_tuple t1 = tuple(1.0, 2.0, 3.0, 1.0);
	t_tuple t2 = tuple(1.0, 2.0, 3.0, 4.0);

	assert(t1.x == 1.0);
	assert(t1.y == 2.0);
	assert(t1.z == 3.0);
	assert(t1.w == 1.0);

	assert(t2.x == 1.0);
	assert(t2.y == 2.0);
	assert(t2.z == 3.0);
	assert(t2.w == 4.0);
	printf("Tuple creation tests passed\n");
}

void test_print_tuple()
{
    t_tuple t = tuple(1.0, 2.0, 3.0, 4.0);
    print_tuple(t);
	printf("Print tuple tests passed\n");
}

void	test_point_creation()
{
	t_tuple	p = point(1.0, 2.0, 3.0);

	assert(p.x == 1.0);
	assert(p.y == 2.0);
	assert(p.z == 3.0);
	assert(p.w == 1.0);
	printf("Point creation tests passed\n");
}

void	test_vector_creation()
{
	t_tuple	v = vector(1.0, 2.0, 3.0);

	assert(v.x == 1.0);
	assert(v.y == 2.0);
	assert(v.z == 3.0);
	assert(v.w == 0.0);
	printf("Vector creation tests passed\n");
}

void	test_adding_two_tuples()
{
	t_tuple t1 = tuple(1.0, 2.0, 3.0, 5.0);
	t_tuple t2 = tuple(4.0, 3.0, 2.0, 5.0);
	t_tuple r = add_tuples(t1, t2);

	assert(r.x == 5.0);
	assert(r.y == 5.0);
	assert(r.z == 5.0);
	assert(r.w == 10.0);
	printf("Adding two tuples tests passed\n");
}

void	test_subtracting_two_tuples()
{
	t_tuple t1 = tuple(1.0, 2.0, 3.0, 5.0);
	t_tuple t2 = tuple(4.0, 3.0, 2.0, 5.0);

	t_tuple r1 = subtract_tuples(t1, t2);
	t_tuple r2 = subtract_tuples(t2, t1);

	assert(r1.x == -3.0);
	assert(r1.y == -1.0);
	assert(r1.z == 1.0);
	assert(r1.w == 0.0);

	assert(r2.x == 3.0);
	assert(r2.y == 1.0);
	assert(r2.z == -1.0);
	assert(r2.w == 0.0);
	printf("Subtracting two tuples tests passed\n");
}

void	test_subtracting_two_points()
{
	t_tuple p1 = point(1.0, 2.0, 3.0);
	t_tuple p2 = point(8.0, 4.0, 1.0);

	t_tuple r1 = subtract_tuples(p1, p2);
	t_tuple r2 = subtract_tuples(p2, p1);

	assert(r1.x == -7.0);
	assert(r1.y == -2.0);
	assert(r1.z == 2.0);
	assert(r1.w == 0.0);

	assert(r2.x == 7.0);
	assert(r2.y == 2.0);
	assert(r2.z == -2.0);
	assert(r2.w == 0.0);
	printf("Subtracting two points tests passed\n");
}

void	test_subtracting_two_vectors()
{
	t_tuple v1 = vector(1.0, 2.0, 3.0);
	t_tuple v2 = vector(8.0, 4.0, 1.0);

	t_tuple r1 = subtract_tuples(v1, v2);
	t_tuple r2 = subtract_tuples(v2, v1);

	assert(r1.x == -7.0);
	assert(r1.y == -2.0);
	assert(r1.z == 2.0);
	assert(r1.w == 0.0);

	assert(r2.x == 7.0);
	assert(r2.y == 2.0);
	assert(r2.z == -2.0);
	assert(r2.w == 0.0);
	printf("Subtracting two vectors tests passed\n");
}

void	test_negate_tuple()
{
	t_tuple	t = tuple(3.0, 2.0, 1.0, 8.0);
	t_tuple r = negate_tuple(t);

	assert(r.x == -3.0);
	assert(r.y == -2.0);
	assert(r.z == -1.0);
	assert(r.w == 8.0);
	printf("Negating tuple tests passed\n");
}

void	test_negate_point()
{
	t_tuple	p = point(3.0, 2.0, 1.0);
	t_tuple r = negate_tuple(p);

	assert(r.x == -3.0);
	assert(r.y == -2.0);
	assert(r.z == -1.0);
	assert(r.w == 1.0);
	printf("Negating point tests passed\n");
}

void	test_negate_vector()
{
	t_tuple	v = vector(3.0, 2.0, 1.0);
	t_tuple r = negate_tuple(v);

	assert(r.x == -3.0);
	assert(r.y == -2.0);
	assert(r.z == -1.0);
	assert(r.w == 0.0);
	printf("Negating vector tests passed\n");
}

int main()
{
	test_tuple_creation();
	test_print_tuple();
	test_point_creation();
	test_vector_creation();
	test_adding_two_tuples();
	test_subtracting_two_tuples();
	test_subtracting_two_points();
	test_subtracting_two_vectors();
	test_negate_tuple();
	test_negate_point();
	test_negate_vector();
	printf("All tests passed!\n");
	return (0);
}
