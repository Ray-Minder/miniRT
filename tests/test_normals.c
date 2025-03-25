#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/tuples.h"
#include "../include/scene.h"
#include "../include/normals.h"

bool compare_tuple(t_tuple a, t_tuple b)
{
	return (compare_doubles(a.x, b.x) && compare_doubles(a.y, b.y) && compare_doubles(a.z, b.z) && compare_doubles(a.w, b.w));
}

void test_normal_at()
{
	t_object	sphere;
	t_tuple		intersect;
	t_tuple		normal;

	sphere.position = point(0, 0, 0);
	sphere.diameter = 2;
	sphere.type = SPHERE;
	intersect = point(1, 0, 0);
	normal = normal_at_sphere(&sphere, intersect);
	print_tuple(normal);
	print_tuple(vector(1, 0, 0));
	printf("%i\n", compare_tuple(normal, vector(1, 0, 0)));
	assert(compare_tuple(normal, vector(1, 0, 0)));

	intersect = point(0, 1, 0);
	normal = normal_at_sphere(&sphere, intersect);
	assert(compare_tuple(normal, vector(0, 1, 0)));

	intersect = point(0, 0, 1);
	normal = normal_at_sphere(&sphere, intersect);
	assert(compare_tuple(normal, vector(0, 0, 1)));

	intersect = point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3);
	normal = normal_at_sphere(&sphere, intersect);
	assert(compare_tuple(normal, vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3)));

	// intersect = point(0, 0, 0);
	// normal = normal_at_sphere(&sphere, intersect);
	// assert(compare_tuple(normal, vector(0, 0, 0)));

	intersect = point(-1, 0, 0);
	normal = normal_at_sphere(&sphere, intersect);
	assert(compare_tuple(normal, vector(-1, 0, 0)));

	intersect = point(0, -1, 0);
	normal = normal_at_sphere(&sphere, intersect);
	assert(compare_tuple(normal, vector(0, -1, 0)));

	intersect = point(0, 0, -1);
	normal = normal_at_sphere(&sphere, intersect);
	assert(compare_tuple(normal, vector(0, 0, -1)));

	sphere.position = point(0, 1, 0);
	intersect = point(0, 2, 0);
	normal = normal_at_sphere(&sphere, intersect);
	print_tuple(normal);

	sphere.position = point(0, 1, 0);
	intersect = point(0, 1.70711, -0.70711);
	normal = normal_at_sphere(&sphere, intersect);
	print_tuple(normal);
	printf("All normal_at_sphere tests passed!\n");
}

int main(void)
{
	test_normal_at();
	printf("All tests passed!\n");
	return (0);
}	