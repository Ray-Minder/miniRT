#include "../../include/minirt.h"

//	=== Function Declarations ===

t_matrix	*create_matrix(int rows, int columns);
void		initialize_matrix(t_matrix *matrix, double *data, int data_size);
t_matrix	*copy_matrix(t_matrix *m);
t_matrix	*identity(int size);

//	=== Function Definitions ===

t_matrix	*create_matrix(int rows, int columns)
{
	t_matrix	*matrix;
	int			i;

	matrix = malloc(sizeof(t_matrix));
	if (!matrix)
		return (print_errno("create_matrix"), NULL);
	matrix->rows = rows;
	matrix->columns = columns;
	matrix->values = ft_calloc(rows, sizeof(double *));
	if (!matrix->values)
		return (free(matrix), print_errno("create_matrix"), NULL);
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
			return (print_errno("create_matrix"), NULL);
		}
	}
	return (matrix);
}

void	initialize_matrix(t_matrix *matrix, double *data, int data_size)
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

t_matrix	*copy_matrix(t_matrix *m)
{
	t_matrix	*copy;
	int			r;
	int			c;

	if (!is_matrix_initialized(m))
		return (print_error_msg("Error copying matrix"), NULL);
	copy = create_matrix(m->rows, m->columns);
	if (!copy)
		return (print_error_msg("Error copying matrix"), NULL);
	r = -1;
	while (++r < m->rows)
	{
		c = -1;
		while (++c < m->columns)
			copy->values[r][c] = m->values[r][c];
	}
	return (copy);
}

t_matrix	*identity(int size)
{
	t_matrix	*_identity;
	int			r;
	int			c;

	_identity = create_matrix(size, size);
	if (!_identity)
		return (print_error_msg("Error creating identity matrix"), NULL);
	r = -1;
	while (++r < size)
	{
		c = -1;
		while (++c < size)
		{
			if (r == c)
				_identity->values[r][c] = 1.0;
			else
				_identity->values[r][c] = 0.0;
		}
	}
	return (_identity);
}
