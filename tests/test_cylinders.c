#include "../include/minirt.h"

void test_cylinder_intersect(t_tuple point, t_tuple direction, double expected_t0, double expected_t1)
{
	printf("Testing cylinder intersection with expected t0: %f, expected t1: %f\n", expected_t0, expected_t1);
	t_x			*xs;
	t_ray		ray;
	t_object	cylinder;

	cylinder.type = CYLINDER;
	cylinder.transform = identity(4);
	cylinder.inverse_transform = invert_matrix(cylinder.transform);
	direction = normalize_tuple(direction);
	ray = create_ray(point, direction);
	xs = intersect(&ray, &cylinder);
	assert(compare_doubles(xs->t, expected_t0));
	assert(compare_doubles(xs->next->t, expected_t1));
	free(xs);
	printf("Cylinder intersection test passed.\n");
}

void test_cylinder()
{
	// Missing
	test_cylinder_intersect(point(0, 0, 0), vector(0, 1, 0), 0.0, 0.0);
	test_cylinder_intersect(point(1, 0, 0), vector(0, 1, 0), 0.0, 0.0);
	test_cylinder_intersect(point(0, 0, -5), vector(1, 1, 1), 0.0, 0.0);
	
	// Hitting
	test_cylinder_intersect(point(1, 0, -5), vector(0, 0, 1), 5.0, 5.0);
	test_cylinder_intersect(point(0, 0, -5), vector(0, 0, 1), 4.0, 6.0);
	test_cylinder_intersect(point(0.5, 0, -5), vector(0.1, 1, 1), 6.80798, 7.08872);
}


int main(void)
{
	test_cylinder();
	printf("All tests passed.\n");
	return (0);
}