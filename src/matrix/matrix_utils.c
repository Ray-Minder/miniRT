#include "../../include/matrices.h"

//	=== Function Declarations ===

void 	free_matrix(t_matrix **matrix);
void 	free_array_of_matrices(t_matrix ***matrices);
int		size_of_array_of_matrices(t_matrix **matrices);
bool	is_matrix_initialized(t_matrix *matrix);
void 	print_matrix(t_matrix* matrix);

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

void free_array_of_matrices(t_matrix ***matrices)
{
	int	i;

	if (!matrices || !*matrices)
		return ;
	i = 0;
	while ((*matrices)[i])
	{
		free_matrix(matrices[i]);
		i++;
	}
	*matrices = NULL;
	return ;
}

int	size_of_array_of_matrices(t_matrix **matrices)
{
	int	i;

	if (!matrices)
		return (0);
	i = 0;
	while (matrices[i] != NULL)
		i++;
	return (i);
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
