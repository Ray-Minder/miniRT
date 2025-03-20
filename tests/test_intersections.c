#include "../include/intersect.h"
#include <assert.h>
#include <stdio.h>

void test_sphere_intersect()
{
	t_ray ray;
	t_object sphere;
	t_xs	intersect;

	ray = create_ray(tuple(0, 0, -5, 1), tuple(0, 0, 1, 0));
	sphere.diameter = 2;
	sphere.position = tuple(0, 0, 0, 1);
	intersect = sphere_intersect(&ray, &sphere);
	assert(intersect.count == 2);
	assert(intersect.t[0] == 4.0);
	assert(intersect.t[1] == 6.0);

	ray = create_ray(point(0, 1, -5), vector(0, 0, 1));
	intersect = sphere_intersect(&ray, &sphere);
	assert(intersect.count == 2);
	assert(intersect.t[0] == 5.0);
	assert(intersect.t[1] == 5.0);

	ray = create_ray(point(0, 2, -5), vector(0, 0, 1));
	intersect = sphere_intersect(&ray, &sphere);
	assert(intersect.count == 0);

	ray = create_ray(point(0, 0, 0), vector(0, 0, 1));
	intersect = sphere_intersect(&ray, &sphere);
	assert(intersect.count == 2);
	assert(intersect.t[0] == -1.0);
	assert(intersect.t[1] == 1.0);

	ray = create_ray(point(0, 0, 5), vector(0, 0, 1));
	intersect = sphere_intersect(&ray, &sphere);
	assert(intersect.count == 2);
	assert(intersect.t[0] == -6.0);
	assert(intersect.t[1] == -4.0);

	printf("Test sphere intersections passed!\n");
}

int main()
{
	test_sphere_intersect();
	t_ray ray = create_ray(point(5, 0, 0), vector(0, 0, 1));
	printf("%f\n", calculate_discriminant(&ray));

	printf("All intersection tests passed");
}