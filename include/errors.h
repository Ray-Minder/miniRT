/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:15:14 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:15:15 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "minirt.h"

typedef enum e_error
{
	SUCCESS,
	INVALID_FILENAME,
	NO_ACCESS,
	INVALID_ELEMENT,
	SPLIT_ERROR,
	INVALID_DOUBLE,
	INVALID_INT,
	INVALID_ARG_COUNT,
	TOO_MANY_AMBIENT_LIGHTS,
	NO_AMBIENT_LIGHT,
	TOO_MANY_CAMERAS,
	NO_CAMERA,
	TOO_MANY_LIGHTS,
	NO_LIGHTS,
	FOV_OUT_OF_RANGE,
	DOUBLE_OUT_OF_RANGE,
	MALLOC_FAIL,
	INVALID_DIRECTION_VECTOR,
	MLX_ERROR,
	ERROR_COUNT
}	t_error;

#endif