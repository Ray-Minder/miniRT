/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verify_filename.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:13:57 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:13:59 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

bool	verify_filename(char *filename);

//	=== Function Definitions ===

bool	verify_filename(char *filename)
{
	const char	*extension = ft_strrchr(filename, '.');

	if (!extension || ft_strncmp(extension, ".rt", 4) != 0)
		return (false);
	return (true);
}
