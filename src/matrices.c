#include "../include/matrices.h"
#include <stdio.h>
#include <stdlib.h>

void free_matrix(t_matrix *matrix)
{
	free(matrix->data);
}

void initialize_matrix(t_matrix *matrix, double *data, int data_size)
{
	int	i;

	i = 0;
	while (i < matrix->rows * matrix->columns)
	{
		if (i >= data_size)
			matrix->data[i] = 0;
		else
			matrix->data[i] = data[i];
		i++;
	}
}

t_matrix	create_matrix(int rows, int columns)
{
	t_matrix	matrix;

	matrix.rows = rows;
	matrix.columns = columns;
	matrix.data = malloc(sizeof(double) * rows * columns);
	if (!matrix.data)
	{
		perror("malloc failed to allocate memory for matrix");
		matrix.rows = 0;
		matrix.columns = 0;
	}
	return (matrix);
}

void print_matrix(t_matrix* matrix)
{
	int	i;
	int	j;
	int k;

	i = 0;
	k = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->columns)
		{
			printf("%f ", matrix->data[k]);
			j++;
			k++;
		}
		printf("\n");
		i++;
	}
}


// int main(void)
// {
// 	t_matrix	m1;
// 	t_matrix	m2;
// 	m1 = create_matrix(1, 1);
// 	m2 = create_matrix(15, 15);
// 	initialize_matrix(&m1, (double[]){1}, 1);
// 	initialize_matrix(&m2, (double[5]){5}, 1);
// 	print_matrix(&m1);
// 	printf("\n");
// 	print_matrix(&m2);

// 	if (compare_matrices(m1, m2))
// 	{
// 		printf("Matrices are the same");
// 	}
// 	else
// 		printf("matrices are different");
	
// 	return (0);
// }

// t_matrix	create_matrix(int rows, int cols)
// {
// 	t_matrix	matrix;
// 	int			i;

// 	matrix.rows = rows;
// 	matrix.cols = cols;
// 	matrix.values = (double **)malloc(sizeof(double *) * rows);
// 	i = 0;
// 	while (i < rows)
// 	{
// 		matrix.values[i] = (double *)malloc(sizeof(double) * cols);
// 		i++;
// 	}
// 	return (matrix);
// }

// void	free_matrix(t_matrix matrix)
// {
// 	int	i;

// 	i = 0;
// 	while (i < matrix.rows)
// 	{
// 		free(matrix.values[i]);
// 		i++;
// 	}
// 	free(matrix.values);
// }

// void	print_matrix(t_matrix matrix)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < matrix.rows)
// 	{
// 		j = 0;
// 		while (j < matrix.cols)
// 		{
// 			printf("%f ", matrix.values[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

// void	set_matrix_value(t_matrix *matrix, int row, int col, double value)
// {
// 	matrix->values[row][col] = value;
// }

// double	get_matrix_value(t_matrix matrix, int row, int col)
// {
// 	return (matrix.values[row][col]);
// }