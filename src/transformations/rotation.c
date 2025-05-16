/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:03:40 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:03:41 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/**
 * @brief	Creates a rotation matrix around the X-axis.
 * 
 * @param	radians	The angle in radians.
 * @return	A pointer to the rotation matrix.
 * 			Returns NULL if an error occurs.
 * @note	The rotation matrix is created using the following formula:
 * 		| 1      0           0          |
 * 		| 0		cos(r)		-sin(r)		|
 * 		| 0		sin(r)		cos(r)		|
 * 		| 0      0           0          |
 */
t_matrix	*rotation_x(double radians)
{
	t_matrix	*rotation_matrix;
	double		cosine;
	double		sine;

	rotation_matrix = identity(4);
	if (!is_matrix_initialized(rotation_matrix))
	{
		perror("Rotation_x");
		return (NULL);
	}
	cosine = cos(radians);
	sine = sin(radians);
	rotation_matrix->values[1][1] = cosine;
	rotation_matrix->values[1][2] = -sine;
	rotation_matrix->values[2][1] = sine;
	rotation_matrix->values[2][2] = cosine;
	return (rotation_matrix);
}

/**
 * @brief	Creates a rotation matrix around the Y-axis.
 * 
 * @param	radians	The angle in radians.
 * @return	A pointer to the rotation matrix.
 * 			Returns NULL if an error occurs.
 * @note	The rotation matrix is created using the following formula:
 * 		| cos(r)	0		sin(r)		0	|
 * 		| 0			1		0			0	|
 * 		| -sin(r)	0		cos(r)		0	|
 * 		| 0			0		0			1	|
 */
t_matrix	*rotation_y(double radians)
{
	t_matrix	*rotation_matrix;
	double		cosine;
	double		sine;

	rotation_matrix = identity(4);
	if (!is_matrix_initialized(rotation_matrix))
	{
		perror("Rotation_y");
		return (NULL);
	}
	cosine = cos(radians);
	sine = sin(radians);
	rotation_matrix->values[0][0] = cosine;
	rotation_matrix->values[0][2] = sine;
	rotation_matrix->values[2][0] = -sine;
	rotation_matrix->values[2][2] = cosine;
	return (rotation_matrix);
}

/**
 * @brief	Creates a rotation matrix around the Z-axis.
 * 
 * @param	radians	The angle in radians.
 * @return	A pointer to the rotation matrix.
 * 			Returns NULL if an error occurs.
 * @note	The rotation matrix is created using the following formula:
 * 		| cos(r)	-sin(r)	0		0	|
 * 		| sin(r)	cos(r)	0		0	|
 * 		| 0			0		1		0	|
 * 		| 0			0		0		1	|
 */
t_matrix	*rotation_z(double radians)
{
	t_matrix	*rotation_matrix;
	double		cosine;
	double		sine;

	rotation_matrix = identity(4);
	if (!is_matrix_initialized(rotation_matrix))
	{
		perror("Rotation_z");
		return (NULL);
	}
	cosine = cos(radians);
	sine = sin(radians);
	rotation_matrix->values[0][0] = cosine;
	rotation_matrix->values[0][1] = -sine;
	rotation_matrix->values[1][0] = sine;
	rotation_matrix->values[1][1] = cosine;
	return (rotation_matrix);
}
