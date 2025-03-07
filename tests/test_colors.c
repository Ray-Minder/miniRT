#include "../include/colors.h"
#include <assert.h>

void	test_color_creation()
{
	t_tuple c = color(1.0, 2.0, 3.0);

	assert(c.x == 1.0);
	assert(c.y == 2.0);
	assert(c.z == 3.0);
	assert(c.w == 0.0);
	printf("Color creation tests passed.\n");
}

void	test_adding_colors()
{
	t_tuple c1 = color(0.9, 0.6, 0.75);
	t_tuple c2 = color(0.7, 0.1, 0.25);
	t_tuple r = add_tuples(c1, c2);

	assert(r.x == 1.6);
	assert(r.y == 0.7);
	assert(r.z == 1.0);
	assert(r.w == 0.0);
	printf("Adding two colors tests passed.\n");
}

int	main(void)
{
	test_color_creation();

	printf("All color tests passed.\n");
	return (0);
}

