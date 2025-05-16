/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translation.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:03:36 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:03:37 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/**
 * @brief	Creates a translation matrix.
 * 
 * @param	x	The translation factor along the x-axis.
 * @param	y	The translation factor along the y-axis.
 * @param	z	The translation factor along the z-axis.
 * @return	A pointer to the translation matrix.
 * 			Returns NULL if an error occurs.
 * @note	The translation matrix is created using the following formula:
 * 	|	1	0	0	x |
 * 	|	0	1	0	y |
 * 	|	0	0	1	z |
 * 	|	0	0	0	1 |
 */
t_matrix	*translation(double x, double y, double z)
{
	t_matrix	*translation_matrix;

	translation_matrix = identity(4);
	if (!is_matrix_initialized(translation_matrix))
	{
		perror("Translation");
		return (NULL);
	}
	translation_matrix->values[0][3] = x;
	translation_matrix->values[1][3] = y;
	translation_matrix->values[2][3] = z;
	return (translation_matrix);
}

/**
 * @brief	Creates a translation matrix from a tuple.
 * 
 * @param	tuple	The tuple representing the translation factors.
 * @return	A pointer to the translation matrix.
 * 			Returns NULL if an error occurs.
 */
t_matrix	*translate_from_tuple(t_tuple tuple)
{
	t_matrix	*translation_matrix;

	translation_matrix = identity(4);
	if (!is_matrix_initialized(translation_matrix))
	{
		perror("Translate from tuple");
		return (NULL);
	}
	translation_matrix->values[0][3] = tuple.x;
	translation_matrix->values[1][3] = tuple.y;
	translation_matrix->values[2][3] = tuple.z;
	return (translation_matrix);
}
