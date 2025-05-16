/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:04 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:05 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
* Test 1
*/

// int	main(void)
// {
// 	char	str[] = "LOWERCASE SENTENCE.";
// 	int		i;

// 	i = 0;
// 	while (i < ft_strlen(str))
// 	{
// 		str[i] = ft_tolower(str[i]);
// 		i++;
// 	}
// 	printf("%s\n", str);
// }
