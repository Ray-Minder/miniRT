#include "../include/matrices.h"

t_matrix	*create_matrix(int rows, int columns)
{
	t_matrix	*matrix;

	matrix = malloc(sizeof(t_matrix));
	if (!matrix)
	{
		perror("Failed to allocate memory for matrix");
		return (NULL);
	}
	matrix->rows = rows;
	matrix->columns = columns;
	matrix->data = malloc(sizeof(double) * rows * columns);
	if (!matrix->data)
	{
		perror("Failed to allocate memory for matrix data");
		free(matrix);
		return (NULL);
	}
	return (matrix);
}

void free_matrix(t_matrix **matrix)
{
	free((*matrix)->data);
	free(*matrix);
	*matrix = NULL;
	return ;
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

bool	is_matrix_initialized(t_matrix *matrix)
{
	if (!matrix || !matrix->data)
		return (false);
	return (true);
}

double	get_value(t_matrix *matrix, int row, int col)
{
	if (!is_matrix_initialized(matrix))
	{
		printf("Impossible to get the value of an uninitialized matrix\n");
		return (0.0);
	}
	return (matrix->data[row * matrix->columns + col]);
}

void	set_value(t_matrix *matrix, int row, int col, double value)
{
	if (!is_matrix_initialized(matrix))
	{
		printf("Impossible to set the value of an uninitialized matrix\n");
		return ;
	}
	matrix->data[row * matrix->columns + col] = value;
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

bool	compare_matrices(t_matrix *a, t_matrix *b)
{
	int	i;

	if (!is_matrix_initialized(a) || !is_matrix_initialized(b))
		return (false); //Un-initialized matrices are a default false.
	if (a->rows != b->rows || a->columns != b->columns)
		return (false);
	i = 0;
	while (i < a->rows * a->columns)
	{
		if (!compare_doubles(a->data[i], b->data[i]))
			return (false);
		i++;
	}
	return (true);
}

t_tuple	get_row_as_tuple(t_matrix *matrix, int row)
{
	t_tuple	tuple;
	int		col;

	tuple = initialize_tuple(0,0,0,0);
	if (!is_matrix_initialized(matrix))
		return (tuple);
	col = 0;
	while (col < matrix->columns)
	{
		tuple.x = matrix->data[row * matrix->columns + col];
		col++;
	}
}

t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			r;
	int			c;
	int			i;
	int			dot_product;

	if (!is_matrix_initialized(a) || !is_matrix_initialized(b))
		return (NULL);
	if (a->columns != b->rows)
		return (NULL);
	result = create_matrix(a->rows, b->columns);
	if (!result)
	{
		perror("Error at multiply matrices");
		return (NULL);
	}
	r = -1;
	while (++r < a->rows)
	{
		c = -1;
		while (++c < b->columns)
		{
			i = -1;
			while (++i < a->rows * b->columns)
				result->data[]
		}
	}
}

