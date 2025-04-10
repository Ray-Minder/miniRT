#include "../../include/minirt.h"

/**
 * @brief	Creates a shearing matrix.
 * 
 * @param	xy	The shearing factor in the x-y direction.
 * @param	xz	The shearing factor in the x-z direction.
 * @param	yx	The shearing factor in the y-x direction.
 * @param	yz	The shearing factor in the y-z direction.
 * @param	zx	The shearing factor in the z-x direction.
 * @param	zy	The shearing factor in the z-y direction.
 * @return	A pointer to the shearing matrix.
 * 			Returns NULL if an error occurs.
 * @note	The shearing matrix is created using the following formula:
 * 	|	1	xy	xz	0 |
 * 	|	yx	1	yz	0 |
 * 	|	zx	zy	1	0 |
 * 	|	0	0	0	1 |
 */
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
