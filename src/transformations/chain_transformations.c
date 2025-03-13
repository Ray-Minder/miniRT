#include "../../include/transformations.h"

t_matrix	*chain_transformations(t_matrix *matrices[])
{
	t_matrix	*chained_matrix;
	t_matrix	*current;
	t_matrix	*temp;
	int			size;

	size = size_of_array_of_matrices(matrices) - 1;
	if (size == 1)
		return (matrices[0]);
	chained_matrix = matrices[size];
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
