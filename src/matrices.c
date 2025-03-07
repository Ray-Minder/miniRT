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

