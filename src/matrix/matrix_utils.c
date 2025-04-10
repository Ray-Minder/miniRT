# include "../../include/minirt.h"

//	=== Function Declarations ===

void 	free_matrix(t_matrix **matrix);
void 	free_array_of_matrices(t_matrix ***matrices);
int		size_of_array_of_matrices(t_matrix **matrices);
bool	is_matrix_initialized(t_matrix *matrix);
void 	print_matrix(t_matrix* matrix);

//	=== Function Definitions ===

/**
 * @brief	Frees the memory allocated for a matrix.
 * 
 * @param	matrix	Pointer to the matrix to be freed.
 * @return	None.
 */
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

/**
 * @brief	Frees the memory allocated for an array of matrices.
 * 
 * @param	matrices	Pointer to the array of matrices to be freed.
 * @return	None.
 * @note	Each matrix in the array is freed,
 * 			and the array itself is set to NULL.
 */
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

/**
 * @brief 	Calculates the size of an array of matrices.
 * 
 * @param 	matrices 	Pointer to the array of matrices.
 * @return 	The size of the array.
 */
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

/**
 * @brief 	Checks if a matrix is initialized.
 * 
 * @param 	matrix 	Pointer to the matrix to check.
 * @return 	True if the matrix is initialized, false otherwise.
 * @note 	A matrix is considered initialized if it has been allocated
 * 			and its values are not NULL.	
 */
bool	is_matrix_initialized(t_matrix *matrix)
{
	if (!matrix || !matrix->values)
		return (false);
	return (true);
}

/**
 * @brief 	Prints the contents of a matrix.
 * 
 * @param 	matrix 	Pointer to the matrix to print.
 * @return 	None.
 */
void print_matrix(t_matrix *matrix)
{
	int	i;
	int	j;

	if (!matrix || !matrix->values)
	{
		printf("There's no matrix to print.\n");
		return ;
	}
	i = -1;
	while (++i < matrix->rows)
	{
		j = -1;
		while (++j < matrix->columns)
			printf("%f ", matrix->values[i][j]);
		printf("\n");
	}
}
