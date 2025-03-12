#include "../../include/matrices.h"

//	=== Function Declarations ===

void 	free_matrix(t_matrix **matrix);
bool	is_matrix_initialized(t_matrix *matrix);
void 	print_matrix(t_matrix* matrix);
t_tuple	get_row_as_tuple(t_matrix *m, int row);

//	=== Function Definitions ===

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

bool	is_matrix_initialized(t_matrix *matrix)
{
	if (!matrix || !matrix->values)
		return (false);
	return (true);
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

t_tuple	get_row_as_tuple(t_matrix *m, int row)
{
	t_tuple	row_as_tuple;
	int		column;

	if (!is_matrix_initialized(m) || row > m->rows)
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
