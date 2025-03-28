#include "../../include/minirt.h"

#define ROW 0
#define COL 1

//	=== Function Declarations ===

t_matrix	*submatrix(t_matrix	*m, int row, int column);
static bool	init_submatrix(t_matrix	*m,
				t_matrix **submatrix, int row, int column);
double		determinant(t_matrix *m);
double		cofactor(t_matrix *m, int row, int col);
t_matrix	*invert_matrix(t_matrix *m);

//	=== Function Definitions ===

t_matrix	*submatrix(t_matrix	*m, int row, int column)
{
	t_matrix	*submatrix;
	int			i[2];
	int			j[2];

	if (!init_submatrix(m, &submatrix, row, column))
		return (NULL);
	i[ROW] = -1;
	j[ROW] = 0;
	while (++i[ROW] < m->rows)
	{
		if (i[ROW] == row)
			continue ;
		i[COL] = -1;
		j[COL] = 0;
		while (++i[COL] < m->columns)
		{
			if (i[COL] == column)
				continue ;
			submatrix->values[j[ROW]][j[COL]] = m->values[i[ROW]][i[COL]];
			j[COL]++;
		}
		j[ROW]++;
	}
	return (submatrix);
}

static bool	init_submatrix(t_matrix	*m,
				t_matrix **submatrix, int row, int column)
{
	if (!is_matrix_initialized(m) || m->rows < 1 || m->columns < 1
		|| row > m->rows || column > m->columns)
		return (print_error_msg("Error at submatrix"), false);
	*submatrix = create_matrix(m->rows - 1, m->columns - 1);
	if (!submatrix)
		return (print_error_msg("Error creating submatrix"), false);
	return (true);
}

double	determinant(t_matrix *m)
{
	double	determinant;
	int		i;

	if (!is_matrix_initialized(m) || m->columns != m->rows)
		return (print_error_msg("Error at determinant"), 0);
	if (m->columns == 1)
		return (m->values[0][0]);
	if (m->columns == 2)
		return (m->values[0][0] * m->values[1][1]
			- m->values[0][1] * m->values[1][0]);
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

	if (!is_matrix_initialized(m) || row > m->rows || col > m->columns)
		return (print_error_msg("Error at cofactor"), 0);
	s_matrix = submatrix(m, row, col);
	minor = determinant(s_matrix);
	if ((row + col) % 2 == 0)
		sign = 1;
	else
		sign = -1;
	return (minor * sign);
}

t_matrix	*invert_matrix(t_matrix *m)
{
	t_matrix	*inverse;
	double		_determinant;
	int			r;
	int			c;
	t_matrix	*_identity;

	if (!is_matrix_initialized(m))
		return (print_error_msg("Error inverting a matrix"), NULL);
	_identity = identity(m->columns); //Check if it fails
	if (compare_matrices(m, _identity))
		return (_identity);
	free_matrix(&_identity);
	_determinant = determinant(m);
	if (compare_doubles(_determinant, 0.0))
		return (print_error_msg("The matrix is not invertible."), NULL);
	inverse = create_matrix(m->rows, m->columns); //Or replace by identity?
	r = -1;
	while (++r < m->rows)
	{
		c = -1;
		while (++c < m->columns)
			inverse->values[c][r] = cofactor(m, r, c) / _determinant;
	}
	return (inverse);
}
