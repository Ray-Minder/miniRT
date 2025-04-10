#include "../../include/minirt.h"

/**
 * @brief	Chains multiple transformation matrices into a single matrix.
 * 
 * @param	matrices	An array of transformation matrices.
 * @return	A pointer to the resulting chained matrix.
 * 			Returns NULL if an error occurs.
 * @note	The last matrix in the array is used as the initial matrix.
 * 			The function multiplies the matrices in reverse order,
 * 			starting from the last one and moving to the first.
 * 			The resulting matrix is the product of all the matrices.
 * 			The function frees the memory of the intermediate matrices.
 */
t_matrix	*chain_transformations(t_matrix *matrices[])
{
	t_matrix	*chained_matrix;
	t_matrix	*current;
	t_matrix	*temp;
	int			size;

	size = size_of_array_of_matrices(matrices) - 1;
	if (size == 0)
		return (matrices[0]);
	chained_matrix = copy_matrix(matrices[size]);
	while (--size >= 0)
	{
		current = matrices[size];
		temp = multiply_matrices(chained_matrix, current);
		if (size > 0)
			free_matrix(&chained_matrix);
		chained_matrix = temp;
	}
	return (chained_matrix);
}
