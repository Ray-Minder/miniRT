#include "../include/intersect.h"
#include <assert.h>
#include <stdio.h>

void test_sphere_intersect()
{
	t_xs		*xs = NULL;
	t_xs		*current = NULL;
	t_ray		ray;
	t_object	sphere;
	
	ray = create_ray(tuple(0, 0, -5, 1), tuple(0, 0, 1, 0));
	sphere.diameter = 2;
	sphere.position = point(0, 0, 0);
	xs = intersect(&ray, &sphere);
	current = xs;
	if (!xs)
	{
		printf("Failure with intersection\n");
		return ;
	}
	assert(current->count == 2);
	assert(current->t[0] == 4.0);
	assert(current->t[1] == 6.0);

	ray = create_ray(point(0, 1, -5), vector(0, 0, 1));
	add_intersection(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	assert(current->count == 2);
	assert(current->t[0] == 5.0);
	assert(current->t[1] == 5.0);

	ray = create_ray(point(0, 2, -5), vector(0, 0, 1));
	add_intersection(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	assert(current->count == 0);

	ray = create_ray(point(0, 0, 0), vector(0, 0, 1));
	add_intersection(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	assert(current->count == 2);
	assert(current->t[0] == -1.0);
	assert(current->t[1] == 1.0);

	ray = create_ray(point(0, 0, 5), vector(0, 0, 1));
	add_intersection(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	assert(current->count == 2);
	assert(current->t[0] == -6.0);
	assert(current->t[1] == -4.0);

	free_intersections_list(&xs);
	printf("Test sphere intersections passed!\n");
}

int main()
{
	test_sphere_intersect();
	t_ray ray = create_ray(point(5, 0, 0), vector(0, 0, 1));
	printf("%f\n", calculate_discriminant(&ray));

	printf("All intersection tests passed\n");
}

//BACKUP
// void test_sphere_intersect()
// {
// 	t_ray		ray;
// 	t_object	sphere;
// 	t_xs		*xs;

// 	ray = create_ray(tuple(0, 0, -5, 1), tuple(0, 0, 1, 0));
// 	sphere.diameter = 2;
// 	sphere.position = point(0, 0, 0);
// 	xs = intersect(&ray, &sphere);
// 	if (!xs)
// 	{
// 		printf("Failure with intersection\n");
// 		return ;
// 	}
// 	assert(xs->count == 2);
// 	assert(xs->t[0] == 4.0);
// 	assert(xs->t[1] == 6.0);

// 	ray = create_ray(point(0, 1, -5), vector(0, 0, 1));
// 	xs = intersect(&ray, &sphere);
// 	if (!xs)
// 	{
// 		printf("Failure with intersection\n");
// 		return ;
// 	}
// 	assert(xs->count == 2);
// 	assert(xs->t[0] == 5.0);
// 	assert(xs->t[1] == 5.0);

// 	ray = create_ray(point(0, 2, -5), vector(0, 0, 1));
// 	xs = intersect(&ray, &sphere);
// 	if (!xs)
// 	{
// 		printf("Failure with intersection\n");
// 		return ;
// 	}
// 	assert(xs->count == 0);

// 	ray = create_ray(point(0, 0, 0), vector(0, 0, 1));
// 	xs = intersect(&ray, &sphere);
// 	if (!xs)
// 	{
// 		printf("Failure with intersection\n");
// 		return ;
// 	}
// 	assert(xs->count == 2);
// 	assert(xs->t[0] == -1.0);
// 	assert(xs->t[1] == 1.0);

// 	ray = create_ray(point(0, 0, 5), vector(0, 0, 1));
// 	xs = intersect(&ray, &sphere);
// 	if (!xs)
// 	{
// 		printf("Failure with intersection\n");
// 		return ;
// 	}
// 	assert(xs->count == 2);
// 	assert(xs->t[0] == -6.0);
// 	assert(xs->t[1] == -4.0);

// 	printf("Test sphere intersections passed!\n");
// }