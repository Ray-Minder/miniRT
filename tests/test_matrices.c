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
}

int main(void)
{
	test_matrix_creation();
	test_compare_matrices();
	printf("All tests passed!\n");
	return (0);
}