# include "../../include/minirt.h"

//	=== Function Declarations ===

t_matrix	*transpose_matrix(t_matrix *m);
t_matrix	*submatrix(t_matrix	*m, int row, int column);
double		determinant(t_matrix *m);
double		cofactor(t_matrix *m, int row, int col);
t_matrix	*invert_matrix(t_matrix *m);

//	=== Function Definitions ===

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

	if (!is_matrix_initialized(m) || m->rows < 1 || m->columns < 1
		|| row > m->rows || column > m->columns)
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

	if (!is_matrix_initialized(m) || row > m->rows || col > m->columns)
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

t_matrix	*invert_matrix(t_matrix *m)
{
	t_matrix	*inverse;
	double		_determinant;
	int			r;
	int			c;
	t_matrix	*_identity;

	if (!is_matrix_initialized(m))
	{
		perror ("Inverse");
		return (NULL);
	}
	_identity = identity(m->columns); //Check if it fails
	if (compare_matrices(m, _identity))
		return (_identity);
	free_matrix(&_identity); 
	_determinant = determinant(m);
	if (compare_doubles(_determinant, 0.0))
	{
		printf("The matrix is not invertible.\n");
		return (NULL);
	}
	inverse = create_matrix(m->rows, m->columns); //Or replace by identity?
	r = -1;
	while (++r < m->rows)
	{
		c = -1;
		while (++c < m->columns)
			inverse->values[c][r] = cofactor(m, r, c) / _determinant;
	}
	return(inverse);
}
