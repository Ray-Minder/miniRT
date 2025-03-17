#include "../../include/matrices.h"

//	=== Function Declarations ===

bool		compare_matrices(t_matrix *a, t_matrix *b);
t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b);
t_tuple		get_row_as_tuple(t_matrix *m, int row);
t_tuple		multiply_matrix_by_tuple(t_matrix *m, t_tuple t);

//	=== Function Definitions ===

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

t_tuple	get_row_as_tuple(t_matrix *m, int row)
{
	t_tuple	row_as_tuple;
	int		column;

	if (!is_matrix_initialized(m) || row > m->rows)
	{
		printf("Error at get_row_as_tuple\n");
		return (tuple(-1, -1, -1, -1));
	}
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

t_tuple	multiply_matrix_by_tuple(t_matrix *m, t_tuple t)
{
	t_tuple	result;
	t_tuple	row[4];

	if (!is_matrix_initialized(m) || m->rows != 4)
	{
		perror("Multiply matrix by tuple error");
		return (tuple(-1, -1, -1, -1));
	}
	row[0] = get_row_as_tuple(m, 0);
	row[1] = get_row_as_tuple(m, 1);
	row[2] = get_row_as_tuple(m, 2);
	row[3] = get_row_as_tuple(m, 3);
	result = tuple(dot_product(row[0], t),
					dot_product(row[1], t), 
					dot_product(row[2], t),
					dot_product(row[3], t));
	return (result);
}
