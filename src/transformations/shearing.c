#include "../../include/transformations.h"

t_matrix	*shearing(double xy, double xz, double yx, 
						double yz, double zx, double zy)
{
	t_matrix	*shearing_matrix;

	shearing_matrix = identity(4);
	if (!is_matrix_initialized(shearing_matrix))
	{
		perror("Shearing");
		return (NULL);
	}
	shearing_matrix->values[0][1] = xy;
	shearing_matrix->values[0][2] = xz;
	shearing_matrix->values[1][0] = yx;
	shearing_matrix->values[1][2] = yz;
	shearing_matrix->values[2][0] = zx;
	shearing_matrix->values[2][1] = zy;
	return (shearing_matrix);
}
