#include "../../include/minirt.h"

//	=== Function Declarations ===

t_matrix	*transpose_matrix(t_matrix *m);
t_matrix	*submatrix(t_matrix	*m, int row, int column);
double		determinant(t_matrix *m);
double		cofactor(t_matrix *m, int row, int col);
t_matrix	*invert_matrix(t_matrix *m);

//	=== Function Definitions ===

/**
 * @brief	Transposes a matrix.
 * 
 * @param	m	Pointer to the matrix to be transposed.
 * @return	A pointer to the transposed matrix, or NULL if an error occurs.
 */
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

/**
 * @brief	Creates a submatrix by removing the specified row and column.
 * 
 * @param	m	Pointer to the original matrix.
 * @param	row	The row index to remove.
 * @param	column	The column index to remove.
 * @return	A pointer to the submatrix, or NULL if an error occurs.
 */
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

/**
 * @brief	Calculates the determinant of a matrix.
 * 
 * @param	m	Pointer to the matrix.
 * @return	The determinant of the matrix, or 0 if an error occurs.
 */
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
		return (m->values[0][0] * m->values[1][1]
			- m->values[0][1] * m->values[1][0]);
	determinant = 0;
	i = -1;
	while (++i < m->columns)
		determinant += m->values[0][i] * cofactor(m, 0, i);
	return (determinant);
}

/**
 * @brief	Calculates the cofactor of a matrix element.
 * 
 * @param	m	Pointer to the matrix.
 * @param	row	The row index of the element.
 * @param	col	The column index of the element.
 * @return	The cofactor of the element, or 0 if an error occurs.
 */
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
	free_matrix(&s_matrix);
	if ((row + col) % 2 == 0)
		sign = 1;
	else
		sign = -1;
	return (minor * sign);
}

/**
 * @brief	Inverts a matrix.
 *
 * @param	m	Pointer to the matrix to be inverted.
 * @return	A pointer to the inverted matrix, or NULL if an error occurs.
 */
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
	_identity = identity(m->columns);
	if (!_identity)
	{
		perror("Inverse");
		return (NULL);
	}
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
	return (inverse);
}
