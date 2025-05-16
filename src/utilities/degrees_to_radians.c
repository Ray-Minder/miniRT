/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   degrees_to_radians.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:03:18 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:03:19 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/**
 * @brief Converts degrees to radians.
 * 
 * @param degrees The angle in degrees to convert.
 * 
 * @return The angle in radians.
 */
double	radians(double degrees)
{
	return (degrees / 180 * PI);
}
