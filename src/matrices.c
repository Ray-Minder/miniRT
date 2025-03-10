#include "../include/matrices.h"

t_matrix	create_matrix(int rows, int cols)
{
	t_matrix	matrix;
	int			i;

	matrix.rows = rows;
	matrix.cols = cols;
	matrix.values = (double **)malloc(sizeof(double *) * rows);
	i = 0;
	while (i < rows)
	{
		matrix.values[i] = (double *)malloc(sizeof(double) * cols);
		i++;
	}
	return (matrix);
}

void	free_matrix(t_matrix matrix)
{
	int	i;

	i = 0;
	while (i < matrix.rows)
	{
		free(matrix.values[i]);
		i++;
	}
	free(matrix.values);
}

void	print_matrix(t_matrix matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix.rows)
	{
		j = 0;
		while (j < matrix.cols)
		{
			printf("%f ", matrix.values[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	set_matrix_value(t_matrix *matrix, int row, int col, double value)
{
	matrix->values[row][col] = value;
}

double	get_matrix_value(t_matrix matrix, int row, int col)
{
	return (matrix.values[row][col]);
}

#include "../include/matrices.h"
#include <stdio.h>
#include <stdlib.h>

void free_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	while (i < matrix->rows)
	{
		free(matrix->data[i]);
		i++;
	}
	free(matrix->data);
}

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
	if (!matrix.data)
	{
		perror("Error allocating memory for matrix");
		exit(1);
	}
	i = 0;
	while (i < rows)
	{
		matrix.data[i] = (double *)malloc(sizeof(double) * colums);
		if (!matrix.data[i])
		{
			perror("Error allocating memory for matrix");
			exit(1);
		}
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


int main(void)
{
	t_matrix	m1;
	t_matrix	m2;
	m1 = create_matrix(1, 1, (double[]){1});
	m2 = create_matrix(2, 2, (double[]){5, 6, 7, 8});
	print_matrix(&m1);
	printf("\n");
	print_matrix(&m2);

	if (compare_matrices(m1, m2))
	{
		printf("Matrices are the same");
	}
	else
		printf("matrices are different");
	
	return (0);
}