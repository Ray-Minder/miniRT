/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reflect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:14:08 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:14:09 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

t_tuple	reflect(t_tuple in, t_tuple normal);

//	=== Function Definitions ===

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	reflected;

	reflected = subtract_tuples(in,
			multiply_tuple_by_scalar(normal, 2 * dot_product(in, normal)));
	return (reflected);
}
