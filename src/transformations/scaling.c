#include "../../include/minirt.h"

/**
 * @brief	Creates a scaling matrix.
 * 
 * @param	x	The scaling factor along the x-axis.
 * @param	y	The scaling factor along the y-axis.
 * @param	z	The scaling factor along the z-axis.
 * @return	A pointer to the scaling matrix.
 * 			Returns NULL if an error occurs.
 * @note	The scaling matrix is created using the following formula:
 * 	|	x	0	0	0 |
 * 	|	0	y	0	0 |
 * 	|	0	0	z	0 |
 * 	|	0	0	0	1 |
 */
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

/**
 * @brief	Creates a scaling matrix from a tuple.
 * 
 * @param	tuple	The tuple representing the scaling factors.
 * @return	A pointer to the scaling matrix.
 * 			Returns NULL if an error occurs.
 * @note	The scaling matrix is created using the following formula:
 * 	|	x	0	0	0 |
 * 	|	0	y	0	0 |
 * 	|	0	0	z	0 |
 * 	|	0	0	0	1 |
 */
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
