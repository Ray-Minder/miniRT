#include "../../include/transformations.h"

t_matrix	*scaling(double x, double y, double z)
{
	t_matrix	*scaling_matrix;

	scaling_matrix = identity(4);
	if (!is_matrix_initialized(scaling_matrix))
	{
		perror("Scaling");
		return (NULL);
	}
	scaling_matrix->values[0][0] = x;
	scaling_matrix->values[1][1] = y;
	scaling_matrix->values[2][2] = z;
	return (scaling_matrix);
}

t_matrix	*scaling_from_tuple(t_tuple tuple)
{
	t_matrix	*scaling_matrix;

	scaling_matrix = identity(4);
	if (!is_matrix_initialized(scaling_matrix))
	{
		perror("Scaling from tuple");
		return (NULL);
	}
	scaling_matrix->values[0][0] = tuple.x;
	scaling_matrix->values[1][1] = tuple.y;
	scaling_matrix->values[2][2] = tuple.z;
	return (scaling_matrix);
}

