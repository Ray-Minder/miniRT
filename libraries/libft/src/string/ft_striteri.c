/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:35 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:36 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

/*
* Test 1
*/

// void	ft_f(unsigned int index, char *strptr)
// {
// 	printf("Iteration %d: %s\n", index + 1, strptr);
// }

// int	main(void)
// {
// 	char	*str;

// 	str = "0123456789";
// 	ft_striteri(str, ft_f);
// }
