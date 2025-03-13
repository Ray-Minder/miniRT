#include "../include/transformations.h"
#include <assert.h>

void	test_translation()
{
	t_tuple		p;
	t_tuple		v;
	t_tuple		translated_point;
	t_tuple		translated_vector;
	t_matrix	*translation_matrix;

	//Translation moves a point
	p = point(-3, 4, 5);
	translation_matrix = translation(5, -3, 2);
	translated_point = multiply_matrix_by_tuple(translation_matrix, p);
	assert(compare_doubles(translated_point.x, 2));
	assert(compare_doubles(translated_point.y, 1));
	assert(compare_doubles(translated_point.z, 7));

	//Translation does not affect a vector
	v = vector(-3, 4, 5);
	translated_vector = multiply_matrix_by_tuple(translation_matrix, v);
	assert(compare_doubles(translated_vector.x, -3));
	assert(compare_doubles(translated_vector.y, 4));
	assert(compare_doubles(translated_vector.z, 5));

	free_matrix(&translation_matrix);
	printf("Test translation passed.\n");
}

void	test_scaling()
{
	t_matrix	*scaling_matrix;
	t_matrix	*reflection;
	t_tuple		p;
	t_tuple		v;
	t_tuple		scaled_tuple;

	scaling_matrix = scaling(2, 3, 4);
	p = point(-4, 6, 8);
	scaled_tuple = multiply_matrix_by_tuple(scaling_matrix, p);
	assert(compare_doubles(scaled_tuple.x, -8));
	assert(compare_doubles(scaled_tuple.y, 18));
	assert(compare_doubles(scaled_tuple.z, 32));

	v = vector(-4, 6, 8);
	scaled_tuple = multiply_matrix_by_tuple(scaling_matrix, v);
	assert(compare_doubles(scaled_tuple.x, -8));
	assert(compare_doubles(scaled_tuple.y, 18));
	assert(compare_doubles(scaled_tuple.z, 32));

	reflection = scaling(-1, 1, 1);
	p = point(2, 3, 4);
	scaled_tuple = multiply_matrix_by_tuple(reflection, p);
	assert(compare_doubles(scaled_tuple.x, -2));
	assert(compare_doubles(scaled_tuple.y, 3));
	assert(compare_doubles(scaled_tuple.z, 4));

	free_matrix(&scaling_matrix);
	free_matrix(&reflection);
	printf("Test scaling passed.\n");
}

void	test_rotation()
{
	t_matrix	*rotation_matrix;
	t_tuple		p;
	t_tuple		rotated_point;

	p = point(0, 1, 0);
	rotation_matrix = rotation_x(PI / 4);
	rotated_point = multiply_matrix_by_tuple(rotation_matrix, p);
	assert(compare_doubles(rotated_point.x, 0));
	assert(compare_doubles(rotated_point.y, 0.7071));
	assert(compare_doubles(rotated_point.z, 0.7071));

	free_matrix(&rotation_matrix);
	rotation_matrix = rotation_x(PI / 2);
	rotated_point = multiply_matrix_by_tuple(rotation_matrix, p);
	assert(compare_doubles(rotated_point.x, 0));
	assert(compare_doubles(rotated_point.y, 0));
	assert(compare_doubles(rotated_point.z, 1));

	free_matrix(&rotation_matrix);
	p = point(0, 0, 1);
	rotation_matrix = rotation_y(PI / 4);
	rotated_point = multiply_matrix_by_tuple(rotation_matrix, p);
	assert(compare_doubles(rotated_point.x, 0.7071));
	assert(compare_doubles(rotated_point.y, 0));
	assert(compare_doubles(rotated_point.z, 0.7071));

	free_matrix(&rotation_matrix);
	rotation_matrix = rotation_y(PI / 2);
	rotated_point = multiply_matrix_by_tuple(rotation_matrix, p);
	assert(compare_doubles(rotated_point.x, 1));
	assert(compare_doubles(rotated_point.y, 0));
	assert(compare_doubles(rotated_point.z, 0));

	free_matrix(&rotation_matrix);
	p = point(0, 1, 0);
	rotation_matrix = rotation_z(PI / 4);
	rotated_point = multiply_matrix_by_tuple(rotation_matrix, p);
	assert(compare_doubles(rotated_point.x, -0.7071));
	assert(compare_doubles(rotated_point.y, 0.7071));
	assert(compare_doubles(rotated_point.z, 0));

	free_matrix(&rotation_matrix);
	rotation_matrix = rotation_z(PI / 2);
	rotated_point = multiply_matrix_by_tuple(rotation_matrix, p);
	assert(compare_doubles(rotated_point.x, -1));
	assert(compare_doubles(rotated_point.y, 0));
	assert(compare_doubles(rotated_point.z, 0));

	free_matrix(&rotation_matrix);
	printf("Test rotation passed.\n");
}

void	test_shearing()
{
	t_matrix	*shearing_matrix;
	t_tuple		p;
	t_tuple		sheared_point;

	p = point(2, 3, 4);
	shearing_matrix = shearing(1, 0, 0, 0, 0, 0);
	sheared_point = multiply_matrix_by_tuple(shearing_matrix, p);
	assert(compare_doubles(sheared_point.x, 5));
	assert(compare_doubles(sheared_point.y, 3));
	assert(compare_doubles(sheared_point.z, 4));

	free_matrix(&shearing_matrix);
	shearing_matrix = shearing(0, 1, 0, 0, 0, 0);
	sheared_point = multiply_matrix_by_tuple(shearing_matrix, p);
	assert(compare_doubles(sheared_point.x, 6));
	assert(compare_doubles(sheared_point.y, 3));
	assert(compare_doubles(sheared_point.z, 4));

	free_matrix(&shearing_matrix);
	shearing_matrix = shearing(0, 0, 1, 0, 0, 0);
	sheared_point = multiply_matrix_by_tuple(shearing_matrix, p);
	assert(compare_doubles(sheared_point.x, 2));
	assert(compare_doubles(sheared_point.y, 5));
	assert(compare_doubles(sheared_point.z, 4));

	free_matrix(&shearing_matrix);
	shearing_matrix = shearing(0, 0, 0, 1, 0, 0);
	sheared_point = multiply_matrix_by_tuple(shearing_matrix, p);
	assert(compare_doubles(sheared_point.x, 2));
	assert(compare_doubles(sheared_point.y, 7));
	assert(compare_doubles(sheared_point.z, 4));

	free_matrix(&shearing_matrix);
	shearing_matrix = shearing(0, 0, 0, 0, 1, 0);
	sheared_point = multiply_matrix_by_tuple(shearing_matrix, p);
	assert(compare_doubles(sheared_point.x, 2));
	assert(compare_doubles(sheared_point.y, 3));
	assert(compare_doubles(sheared_point.z, 6));

	free_matrix(&shearing_matrix);
	shearing_matrix = shearing(0, 0, 0, 0, 0, 1);
	sheared_point = multiply_matrix_by_tuple(shearing_matrix, p);
	assert(compare_doubles(sheared_point.x, 2));
	assert(compare_doubles(sheared_point.y, 3));
	assert(compare_doubles(sheared_point.z, 7));

	free_matrix(&shearing_matrix);
	printf("Test shearing passed.\n");
}

int main(void)
{
	test_translation();
	test_scaling();
	test_rotation();
	test_shearing();
	printf("All tests passed!\n");
	return (0);
}