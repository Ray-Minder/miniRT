/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:37:04 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:37:05 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (n > i)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
* Test 1 - n < the point where the strings being compared
*	start to differ -> return = 0
*/

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	int		n;

// 	str1 = "lalala5l6aac";
// 	str2 = "lalala5l6";
// 	n = 7;
// 	printf("%d\n", memcmp(str1, str2, n));
// 	printf("%d\n", ft_memcmp(str1, str2, n));
// }

/*
* Test 2 - n > the point where the strings being compared start to differ
*/

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	int		n;

// 	str1 = "lalala5l6aac";
// 	str2 = "lalala5l6";
// 	n = 20;
// 	printf("%d\n", memcmp(str1, str2, n));
// 	printf("%d\n", ft_memcmp(str1, str2, n));
// }
