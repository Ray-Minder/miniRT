#include "../include/matrices.h"
#include "../include/utilities.h"
#include <stdbool.h>

bool compare_matrices(t_matrix m1, t_matrix m2)
{
	int i;
	int j;

	i = 0;
	if (m1.rows != m2.rows || m1.colums != m2.colums)
		return (false);
	while (i < m1.rows)
	{
		j = 0;
		while (j < m1.colums)
		{
			if (m1.data[i][j] != m2.data[i][j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}