#include "../include/matrices.h"
#include <stdio.h>
#include <stdlib.h>

void initialize_matrix(t_matrix *matrix, double *data)
{
	int	i;
	int	j;
	int k;

	i = 0;
	k = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->colums)
		{
			matrix->data[i][j] = data[k];
			j++;
			k++;
		}
		i++;
	}
}

t_matrix	create_matrix(int rows, int colums, double *data)
{
	t_matrix	matrix;
	int			i;

	matrix.rows = rows;
	matrix.colums = colums;
	matrix.data = (double **)malloc(sizeof(double *) * rows);
	i = 0;
	while (i < rows)
	{
		matrix.data[i] = (double *)malloc(sizeof(double) * colums);
		i++;
	}
	initialize_matrix(&matrix, data);
	return (matrix);
}

void print_matrix(t_matrix* matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->colums)
		{
			printf("%f ", matrix->data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

// int main(void)
// {
// 	t_matrix	m1;
// 	t_matrix	m2;
// 	m1 = create_matrix(2, 2, (double[]){1, 2, 3, 4});
// 	m2 = create_matrix(2, 2, (double[]){5, 6, 7, 8});
// 	print_matrix(&m1);
// 	printf("\n");
// 	print_matrix(&m2);
	
// 	return (0);
// }