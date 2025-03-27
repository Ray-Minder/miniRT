#include "../include/minirt.h"
#include <assert.h>

void	test_color_creation()
{
	t_color c = color(1, 2, 3);

	assert(c.r == 1);
	assert(c.g == 2);
	assert(c.b == 3);
	printf("Color creation tests passed.\n");
}

// void	test_adding_colors()
// {
// 	t_color c1 = color(0.9, 0.6, 0.75);
// 	t_color c2 = color(0.7, 0.1, 0.25);
// 	t_color r = add_colors(c1, c2);

// 	assert(r.r == 1.6);
// 	assert(r.g == 0.7);
// 	assert(r.b == 1.0);
// 	printf("Adding two colors tests passed.\n");
// }

int	main(void)
{
	test_color_creation();

	printf("All color tests passed.\n");
	return (0);
}

