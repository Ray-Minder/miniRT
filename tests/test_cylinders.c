#include "../include/minirt.h"

void test_cylinder_intersect()
{
	t_ray		ray;
	t_object	cylinder;
	t_x			*xs;
	t_tuple	origin;
	t_tuple	direction;
	cylinder.type = CYLINDER;

	origin = point(1, 0, 0);
	direction = vector(0, 1, 0);
	direction = normalize_tuple(direction);
	ray = create_ray(origin, direction);
	xs = intersect(&ray, &cylinder);
	assert(xs->hit == false);
	
	origin = point(0, 0, 0);
	direction = vector(0, 1, 0);
	direction = normalize_tuple(direction);
	ray = create_ray(origin, direction);
	xs = intersect(&ray, &cylinder);
	assert(xs->hit == false);

	origin = point(0, 0, -5);
	direction = vector(1, 1, 1);
	direction = normalize_tuple(direction);
	ray = create_ray(origin, direction);
	xs = intersect(&ray, &cylinder);
	assert(xs->hit == false);
}

int main(void)
{
	test_cylinder_intersect();
	printf("All tests passed.\n");
	return (0);
}