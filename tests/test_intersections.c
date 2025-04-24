#include "../include/minirt.h"

void test_sphere_intersect()
{
	t_x			*xs = NULL;
	t_x			*current = NULL;
	t_ray		ray;
	t_object	sphere;
	
	ray = create_ray(tuple(0, 0, -5, 1), tuple(0, 0, 1, 0));
	sphere.diameter = 2;
	sphere.pos = point(0, 0, 0);
	sphere.transform = identity(4);
	xs = intersect(&ray, &sphere);
	current = xs;
	if (!xs)
	{
		printf("Failure with intersection\n");
		return ;
	}
	// printf("x0 %f\n", current->t);
	// printf("x1 %f\n", current->next->t);
	assert(current->t == 4.0);
	current = current->next;
	assert(current->t == 6.0);

	ray = create_ray(point(0, 1, -5), vector(0, 0, 1));
	add_intersection_node(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	assert(current->t == 5.0);
	current = current->next;
	assert(current->t == 5.0);

	ray = create_ray(point(0, 2, -5), vector(0, 0, 1));
	add_intersection_node(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	// assert(current->hit == false);

	ray = create_ray(point(0, 0, 0), vector(0, 0, 1));
	add_intersection_node(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	assert(current->t == -1.0);
	current = current->next;
	assert(current->t == 1.0);

	ray = create_ray(point(0, 0, 5), vector(0, 0, 1));
	add_intersection_node(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	assert(current->t == -6.0);
	current = current->next;
	assert(current->t == -4.0);

	free_intersections_list(&xs);
	printf("Test sphere intersections passed!\n");
}

void test_hit()
{
	t_x			*xs = NULL;
	t_x			*current = NULL;
	t_x			*_hit;
	t_ray		ray;
	t_object	sphere;
	
	ray = create_ray(tuple(0, 0, -5, 1), tuple(0, 0, 1, 0));
	sphere.diameter = 2;
	sphere.pos = point(0, 0, 0);
	sphere.transform = identity(4);
	xs = intersect(&ray, &sphere);
	current = xs;
	if (!xs)
	{
		printf("Failure with intersection\n");
		return ;
	}
	_hit = hit(xs);
	assert(_hit->t == 4.0);

	ray = create_ray(point(0, 1, -5), vector(0, 0, 1));
	add_intersection_node(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	_hit = hit(xs);
	assert(_hit->t == 4.0);

	ray = create_ray(point(0, 2, -5), vector(0, 0, 1));
	add_intersection_node(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	// assert(current->hit == false);

	ray = create_ray(point(0, 0, 0), vector(0, 0, 1));
	add_intersection_node(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	_hit = hit(xs);
	assert(_hit->t == 1.0);

	ray = create_ray(point(0, 0, 5), vector(0, 0, 1));
	add_intersection_node(&xs, intersect(&ray, &sphere));
	current = current->next;
	if (!current)
	{
		printf("Failed to add intersection\n");
		return ;
	}
	_hit = hit(xs);
	assert(_hit->t == 1.0);

	free_intersections_list(&xs);
	printf("Test hit passed!\n");
}

void	test_transform()
{
	t_ray		ray;
	t_matrix	*_translation;
	t_matrix	*_scaling;
	t_ray		r2;
	t_object	sphere;
	t_x			*xs;
	
	ray = create_ray(point(1, 2, 3), vector(0, 1, 0));

	_translation = translation(3, 4, 5);
	r2 = transform(&ray, _translation);
	assert(compare_tuples(r2.origin, point(4, 6, 8)));
	assert(compare_tuples(r2.direction, vector(0, 1, 0)));

	_scaling = scaling(2, 3, 4);
	r2 = transform(&ray, _scaling);
	assert(compare_tuples(r2.origin, point(2, 6, 12)));
	assert(compare_tuples(r2.direction, vector(0, 3, 0)));

	sphere.diameter = 2;
	sphere.pos = point(0, 0, 0);
	sphere.transform = identity(4);
	r2 = create_ray(point(0, 0, -5), vector(0, 0, 1));

	set_transform(&sphere, scaling(2, 2, 2));
	xs = intersect(&r2, &sphere);
	assert(xs->hit == true);
	assert(xs->t == 3);
	assert(xs->next->t == 7);

	set_transform(&sphere, translation(5, 0, 0));
	xs = intersect(&r2, &sphere);
	assert(xs->hit == false);

	printf("Test transform passed!\n");
}

int main()
{
	test_sphere_intersect();
	test_hit();
	test_transform();
	// t_ray ray = create_ray(point(5, 0, 0), vector(0, 0, 1));
	// printf("%f\n", calculate_discriminant(&ray));

	printf("All intersection tests passed\n");
}

//BACKUP
// void test_sphere_intersect()
// {
// 	t_ray		ray;
// 	t_object	sphere;
// 	t_x		*xs;

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