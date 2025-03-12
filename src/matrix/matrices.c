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
	if (row > matrix->rows || col > matrix->columns)
	{
		printf("Out of bounds to get the value.\n");
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
	if (row > matrix->rows || col > matrix->columns)
	{
		printf("Out of bounds to set the value.\n");
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

t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			r;
	int			c;
	int			i;

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
			result->values[r][c] = 0;
			while (++i < a->columns)
				result->values[r][c] += a->values[r][i] * b->values[i][c];
		}
	}
	return (result);
}

t_tuple	multiply_matrix_by_tuple(t_matrix *m, t_tuple t)
{
	t_tuple	result;

	if (!is_matrix_initialized(m) || m->rows != 4)
		return (tuple(-1, -1, -1, -1));
	result = tuple(dot_product(get_row_as_tuple(m, 0), t), 
					dot_product(get_row_as_tuple(m, 1), t), 
					dot_product(get_row_as_tuple(m, 2), t),
					dot_product(get_row_as_tuple(m, 3), t));
	return (result);
}

t_tuple	get_row_as_tuple(t_matrix *m, int row)
{
	t_tuple	row_as_tuple;
	int		column;

	if (!is_matrix_initialized(m))
		return (tuple(-1, -1, -1, -1));
	row_as_tuple = tuple(0, 0, 0, 0);
	column = -1;
	while (++column < m->columns && column < 4)
	{
		if (column == 0)
			row_as_tuple.x = m->values[row][column];
        else if (column == 1)
			row_as_tuple.y = m->values[row][column];
        else if (column == 2)
			row_as_tuple.z = m->values[row][column];
        else if (column == 3)
			row_as_tuple.w = m->values[row][column];
	}
	return (row_as_tuple);
}

t_matrix	*transpose_matrix(t_matrix *m)
{
	t_matrix	*transposed;
	int			i;
	int			j;

	if (!is_matrix_initialized(m))
		return (NULL);
	transposed = create_matrix(m->columns, m->rows);
	if (!transposed)
	{
		perror("Transpose matrix");
		return (NULL);
	}
	i = -1;
	while (++i < m->rows)
	{
		j = -1;
		while (++j < m->columns)
			transposed->values[j][i] = m->values[i][j];
	}
	return (transposed);
}

t_matrix	*submatrix(t_matrix	*m, int row, int column)
{
	t_matrix	*submatrix;
	int			r;
	int			c;
	int			i;
	int			j;

	if (!is_matrix_initialized(m) || m->rows < 2 || m->columns < 2)
		return (NULL);
	submatrix = create_matrix(m->rows - 1, m->columns - 1);
	if (!submatrix)
	{
		perror("Submatrix");
		return (NULL);
	}
	i = -1;
	r = 0;
	while (++i < m->rows)
	{
		if (i == row)
			continue ;
		j = -1;
		c = 0;
		while (++j < m->columns)
		{
			if (j == column)
				continue ;
			submatrix->values[r][c] = m->values[i][j];
			c++;
		}
		r++;
	}
	return (submatrix);
}

double	determinant(t_matrix *m)
{
	double	determinant;
	int		i;

	if (!is_matrix_initialized(m) || m->columns != m->rows)
	{
		perror("Determinant");
		return (0);
	}
	if (m->columns == 1)
		return (m->values[0][0]);
	if (m->columns == 2)
		return (m->values[0][0] * m->values[1][1] - m->values[0][1] * m->values[1][0]);
	determinant = 0;
	i = -1;
	while (++i < m->columns)
		determinant += m->values[0][i] * cofactor(m, 0, i);
	return (determinant);
}

double	cofactor(t_matrix *m, int row, int col)
{
	t_matrix	*s_matrix;
	double		minor;
	double		sign;

	if (!is_matrix_initialized(m))
	{
		perror("Cofactor");
		return (0);
	}
	s_matrix = submatrix(m, row, col);
	minor = determinant(s_matrix);
	if ((row + col) % 2 == 0)
		sign = 1;
	else
		sign = -1;
	return (minor * sign);
}
