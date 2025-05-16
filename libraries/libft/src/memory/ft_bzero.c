/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:58 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:59 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

/*
* Test 1
*/

// int	main(void)
// {
// 	char	*str;

// 	str = (char *) malloc (100);
// 	if (!str)
// 		return (0);
// 	ft_strlcpy(str, "Lalala", 7);
// 	printf("%s\n", str);
// 	ft_bzero(str + 2, 4);
// 	printf("%s\n", str);
// 	free (str);
// }