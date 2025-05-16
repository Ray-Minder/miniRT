/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:13:38 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:13:39 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

int	print_error(t_error error);

//	=== Function Definitions ===

int	print_error(t_error error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *) get_error_msg(error), 2);
	ft_putstr_fd("\n", 2);
	return (error);
}
