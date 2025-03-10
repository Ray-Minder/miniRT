#include "../include/matrices.h"
#include "../include/utilities.h"
#include <stdbool.h>

bool compare_matrices(t_matrix m1, t_matrix m2)
{
	int i;

	i = 0;
	if (m1.rows != m2.rows || m1.columns != m2.columns)
		return (false);
	while (i < m1.rows * m1.columns)
	{
			if (!compare_doubles(m1.data[i], m2.data[i]))
				return (false);
		i++;
	}
	return (true);
}