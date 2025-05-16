/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations_1.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:04:23 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:04:24 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

bool		compare_matrices(t_matrix *a, t_matrix *b);
t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b);
t_tuple		get_row_as_tuple(t_matrix *m, int row);
t_tuple		multiply_matrix_by_tuple(t_matrix *m, t_tuple t);
t_matrix	*transpose_matrix(t_matrix *m);

//	=== Function Definitions ===

/**
 * @brief	Compares two matrices for equality.
 * 
 * @param	a	Pointer to the first matrix.
 * @param	b	Pointer to the second matrix.
 * @return	True if the matrices are equal, false otherwise.
 */
bool	compare_matrices(t_matrix *a, t_matrix *b)
{
	int	i;
	int	j;

	if (!is_matrix_initialized(a) || !is_matrix_initialized(b))
		return (false);
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

/**
 * @brief	Multiplies two matrices.
 * 
 * @param	a	Pointer to the first matrix.
 * @param	b	Pointer to the second matrix.
 * @return	A pointer to the resulting matrix, or NULL if an error occurs.
 */
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
		return (print_error_msg("Error multiplying matrices"), NULL);
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

/**
 * @brief	Gets a row from a matrix as a tuple.
 * 
 * @param	m	Pointer to the matrix.
 * @param	row	The row index to retrieve.
 * @return	A tuple representing the row, or an error tuple if an error occurs.
 */
t_tuple	get_row_as_tuple(t_matrix *m, int row)
{
	t_tuple	row_as_tuple;
	int		column;

	if (!is_matrix_initialized(m) || row > m->rows)
		return (print_error_msg("Error getting a matrix row as a tuple"),
			tuple(-1, -1, -1, -1));
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

/**
 * @brief	Multiplies a matrix by a tuple.
 * 
 * @param	m	Pointer to the matrix.
 * @param	t	The tuple to multiply.
 * @return	A tuple representing the result of the multiplication,
 * 			or an error tuple if an error occurs.
 */
t_tuple	multiply_matrix_by_tuple(t_matrix *m, t_tuple t)
{
	t_tuple	result;
	t_tuple	row[4];

	if (!is_matrix_initialized(m) || m->rows != 4)
	{
		return (print_error_msg("Error multiplying a matrix by a tuple"),
			tuple(-1, -1, -1, -1));
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
