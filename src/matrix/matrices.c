#include "../../include/matrices.h"

t_matrix	*create_matrix(int rows, int columns)
{
	t_matrix	*matrix;
	int			i;

	matrix = malloc(sizeof(t_matrix));
	if (!matrix)
	{
		perror("Failed to allocate memory for matrix");
		return (NULL);
	}
	matrix->rows = rows;
	matrix->columns = columns;
	matrix->values = ft_calloc(rows, sizeof(double *));
	if (!matrix->values)
	{
		free(matrix);
		perror("Failed to allocate memory for matrix rows");
		return (NULL);
	}
	i = -1;
	while (++i < matrix->rows)
	{
		matrix->values[i] = ft_calloc(columns, sizeof(double));
		if (!matrix->values[i])
		{
			while (--i >= 0)
            	free(matrix->values[i]);
			free(matrix->values);
			free(matrix);
			perror("Failed to allocate memory for matrix columns");
			return (NULL);
		}
	}
	return (matrix);
}

void free_matrix(t_matrix **matrix)
{
	int	i;

	if (matrix && *matrix)
	{
		i = -1;
		while (++i < (*matrix)->rows)
			free((*matrix)->values[i]);
		free((*matrix)->values);
		free(*matrix);
		*matrix = NULL;
	}
	return ;
}

void initialize_matrix(t_matrix *matrix, double *data, int data_size)
{
	int	i;
	int	j;
	int	index;

	if (!matrix || !matrix->values || !data)
		return ;
	i = -1;
	while (++i < matrix->rows)
	{
		j = -1;
		while (++j < matrix->columns)
		{
			index = i * matrix->columns + j;
			if (index < data_size)
				matrix->values[i][j] = data[index];
			else
				matrix->values[i][j] = 0;
		}
	}
}

bool	is_matrix_initialized(t_matrix *matrix)
{
	if (!matrix || !matrix->values)
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
	return (matrix->values[row][col]);
}

void	set_value(t_matrix *matrix, int row, int col, double value)
{
	if (!is_matrix_initialized(matrix))
	{
		printf("Impossible to set the value of an uninitialized matrix\n");
		return ;
	}
	matrix->values[row][col] = value;
}

void print_matrix(t_matrix* matrix)
{
	int	i;
	int	j;
	int k;

	i = -1;
	k = 0;
	while (++i < matrix->rows)
	{
		j = -1;
		while (++j < matrix->columns)
			printf("%f ", matrix->values[i][j]);
		printf("\n");
	}
}

bool	compare_matrices(t_matrix *a, t_matrix *b)
{
	int	i;
	int	j;

	if (!is_matrix_initialized(a) || !is_matrix_initialized(b))
		return (false); //Un-initialized matrices are a default false.
	if (a->rows != b->rows || a->columns != b->columns)
		return (false);
	i = -1;
	while (++i < a->rows)
	{
		j = -1;
		while (++j < a->columns)
		{
			if (!compare_doubles(a->values[i][j], b->values[i][j]))
				return (false);
		}
	}
	return (true);
}

// t_tuple	get_row_as_tuple(t_matrix *matrix, int row)
// {
// 	t_tuple	tuple;
// 	int		col;

// 	tuple = initialize_tuple(0,0,0,0);
// 	if (!is_matrix_initialized(matrix))
// 		return (tuple);
// 	col = 0;
// 	while (col < matrix->columns)
// 	{
// 		tuple.x = matrix->values[row * matrix->columns + col];
// 		col++;
// 	}
// }

// t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b)
// {
// 	t_matrix	*result;
// 	int			r;
// 	int			c;
// 	int			i;
// 	int			dot_product;

// 	if (!is_matrix_initialized(a) || !is_matrix_initialized(b))
// 		return (NULL);
// 	if (a->columns != b->rows)
// 		return (NULL);
// 	result = create_matrix(a->rows, b->columns);
// 	if (!result)
// 	{
// 		perror("Error at multiply matrices");
// 		return (NULL);
// 	}
// 	r = -1;
// 	while (++r < a->rows)
// 	{
// 		c = -1;
// 		while (++c < b->columns)
// 		{
// 			i = -1;
// 			while (++i < a->rows * b->columns)
// 				result->data[]
// 		}
// 	}
// }

