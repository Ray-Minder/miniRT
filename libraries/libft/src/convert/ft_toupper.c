/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:03 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:04 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
* Test 1
*/

// int	main(void)
// {
// 	char	str[] = "uppercase sentence.";
// 	int		i;

// 	i = 0;
// 	while (i < ft_strlen(str))
// 	{
// 		str[i] = ft_toupper(str[i]);
// 		i++;
// 	}
// 	printf("%s\n", str);
// }
