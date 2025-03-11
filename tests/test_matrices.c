#include "../include/matrices.h"
#include <stdio.h>
#include <assert.h>

void test_matrix_creation()
{
	t_matrix *m1;
	t_matrix *m2;

	m1 = create_matrix(2, 2);
	m2 = create_matrix(3, 3);
	initialize_matrix(m1, (double[]){1.0, 2.0, 3.0, 4.0}, 4);
	initialize_matrix(m2, (double[]){1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}, 9);

	assert(m1->rows == 2);
	assert(m1->columns == 2);
	assert(compare_doubles(m1->values[0][0], 1.0));
	assert(compare_doubles(m1->values[0][1], 2.0));
	assert(compare_doubles(m1->values[1][0], 3.0));
	assert(compare_doubles(m1->values[1][1], 4.0));

	assert(m2->rows == 3);
	assert(m2->columns == 3);
	assert(compare_doubles(m2->values[0][0], 1.0));
	assert(compare_doubles(m2->values[0][1], 2.0));
	assert(compare_doubles(m2->values[0][2], 3.0));
	assert(compare_doubles(m2->values[1][0], 4.0));
	assert(compare_doubles(m2->values[1][1], 5.0));
	assert(compare_doubles(m2->values[1][2], 6.0));
	assert(compare_doubles(m2->values[2][0], 7.0));
	assert(compare_doubles(m2->values[2][1], 8.0));
	assert(compare_doubles(m2->values[2][2], 9.0));
	printf("Matrix creation tests passed.\n");
	free_matrix(&m1);
	free_matrix(&m2);
}

void test_compare_matrices()
{
	t_matrix *m1;
	t_matrix *m2;

	m1 = create_matrix(2, 2);
	m2 = create_matrix(2, 2);
	initialize_matrix(m1, (double[]){1.0, 2.0, 3.0, 4.0}, 4);
	initialize_matrix(m2, (double[]){1.0, 2.0, 3.0, 4.0}, 4);

	assert(compare_matrices(m1, m2) == true);

	m2 = create_matrix(2, 2);
	initialize_matrix(m2, (double[]){5.0, 6.0, 7.0, 8.0}, 4);

	assert(compare_matrices(m1, m2) == false);
	printf("Matrix comparison tests passed.\n");
	free_matrix(&m1);
	free_matrix(&m2);
}

void test_multiply_matrices()
{
	t_matrix *m1;
	t_matrix *m2;
	t_matrix *result;
	t_matrix *expected;

	m1 = create_matrix(2, 2);
	m2 = create_matrix(2, 2);
	initialize_matrix(m1, (double[]){1.0, 2.0, 3.0, 4.0}, 4);
	initialize_matrix(m2, (double[]){5.0, 6.0, 7.0, 8.0}, 4);

	result = multiply_matrices(m1, m2);
	expected = create_matrix(2, 2);
	initialize_matrix(expected, (double[]){19.0, 22.0, 43.0, 50.0}, 4);

	assert(compare_matrices(result, expected) == true);
	printf("Matrix multiplication tests passed.\n");

	free_matrix(&m1);
	free_matrix(&m2);
	free_matrix(&result);
	free_matrix(&expected);
}

void test_row_as_tuple()
{
	t_matrix *matrix = create_matrix(3, 3);
	initialize_matrix(matrix, (double[]){1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}, 9);

	// Extract the first row as a tuple
	t_tuple row = get_row_as_tuple(matrix, 0);

	// Verify the extracted tuple
	assert(compare_doubles(row.x, 1.0));
	assert(compare_doubles(row.y, 2.0));
	assert(compare_doubles(row.z, 3.0));
	assert(compare_doubles(row.w, 0.0));

	row = get_row_as_tuple(matrix, 1);
	assert(compare_doubles(row.x, 4.0));
	assert(compare_doubles(row.y, 5.0));
	assert(compare_doubles(row.z, 6.0));
	assert(compare_doubles(row.w, 0.0));

	row = get_row_as_tuple(matrix, 2);
	assert(compare_doubles(row.x, 7.0));
	assert(compare_doubles(row.y, 8.0));
	assert(compare_doubles(row.z, 9.0));
	assert(compare_doubles(row.w, 0.0));

	free_matrix(&matrix);

	printf("Test row_as_tuple passed.\n");
}

void	test_multiply_matrix_by_tuple()
{
	t_matrix	*matrix;

	matrix = create_matrix(4, 4);
	initialize_matrix(matrix, (double[]){1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0}, 16);

	t_tuple tuple = {1.0, 2.0, 3.0, 1.0};

	t_tuple result = multiply_matrix_by_tuple(matrix, tuple);
	assert(compare_doubles(result.x, 18.0));
	assert(compare_doubles(result.y, 46.0));
	assert(compare_doubles(result.z, 74.0));
	assert(compare_doubles(result.w, 102.0));
	free_matrix(&matrix);

	printf("Test multiply_matrix_by_tuple passed.\n");
}

void	test_transpose_matrix()
{
	t_matrix	*matrix;
	t_matrix	*transposed;

	matrix = create_matrix(4, 4);
	initialize_matrix(matrix, (double[]){1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0}, 16);

	transposed = transpose_matrix(matrix);
	assert(compare_doubles(transposed->values[0][0], 1.0));
	assert(compare_doubles(transposed->values[0][1], 5.0));
	assert(compare_doubles(transposed->values[0][2], 9.0));
	assert(compare_doubles(transposed->values[0][3], 13.0));
	assert(compare_doubles(transposed->values[1][0], 2.0));
	assert(compare_doubles(transposed->values[1][1], 6.0));
	assert(compare_doubles(transposed->values[1][2], 10.0));
	assert(compare_doubles(transposed->values[1][3], 14.0));
	assert(compare_doubles(transposed->values[2][0], 3.0));
	assert(compare_doubles(transposed->values[2][1], 7.0));
	assert(compare_doubles(transposed->values[2][2], 11.0));
	assert(compare_doubles(transposed->values[2][3], 15.0));
	assert(compare_doubles(transposed->values[3][0], 4.0));
	assert(compare_doubles(transposed->values[3][1], 8.0));
	assert(compare_doubles(transposed->values[3][2], 12.0));
	assert(compare_doubles(transposed->values[3][3], 16.0));
	free_matrix(&matrix);
	free_matrix(&transposed);
	printf("Test transpose_matrix passed.\n");
}

int main(void)
{
	test_matrix_creation();
	test_compare_matrices();
	test_multiply_matrices();
	test_row_as_tuple();
	test_multiply_matrix_by_tuple();
	test_transpose_matrix();
	printf("All tests passed!\n");
	return (0);
}