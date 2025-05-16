/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_n.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:20 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:20 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_free_n(void	**ptr, int dimension)
{
	int	i;

	if (!ptr || !*ptr)
		return ;
	if (dimension == 1)
	{
		free(*ptr);
		*ptr = NULL;
		return ;
	}
	i = 0;
	while (ptr[i] != NULL)
	{
		ft_free_n((void **) ptr[i], dimension - 1);
		i++;
	}
	return ;
}
