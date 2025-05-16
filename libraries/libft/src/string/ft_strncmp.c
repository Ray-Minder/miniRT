/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:45 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:46 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (c1[i] && c2[i] && n > i)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	if (i >= n)
		return (c1[i - 1] - c2[i - 1]);
	return (c1[i] - c2[i]);
}

/*
* Test 1 - n = 0 -> return = 0
*/

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	size_t	n;

// 	str1 = "t";
// 	str2 = "b";
// 	n = 0;
// 	printf("%d\n", ft_strncmp(str1, str2, n));
// 	printf("%d\n", strncmp(str1, str2, n));
// }

/*
* Test 2 - n > 0
*/

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	size_t	n;

// 	str1 = "t";
// 	str2 = "";
// 	n = 5;
// 	printf("%d\n", ft_strncmp(str1, str2, n));
// 	printf("%d\n", strncmp(str1, str2, n));
// }

/*
* Test 3 - n < 0, n is an unsigned int, therefore it acts as n > 0
*/

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	size_t	n;

// 	str1 = "t";
// 	str2 = "";
// 	n = -1;
// 	printf("%d\n", ft_strncmp(str1, str2, n));
// 	printf("%d\n", strncmp(str1, str2, n));
// }

/*
* Test 4 - n > 0 && return = 0
*/

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	size_t	n;

// 	str1 = "blablabla";
// 	str2 = "blablabla";
// 	n = 10;
// 	printf("%d\n", ft_strncmp(str1, str2, n));
// 	printf("%d\n", strncmp(str1, str2, n));
// }
