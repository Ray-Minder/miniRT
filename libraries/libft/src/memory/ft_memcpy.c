/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:37:05 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:37:06 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n > i)
	{
		*(char *)(dest + i) = *(const char *)(src + i);
		i++;
	}
	return (dest);
}

/*
* Test 1
*/

// int	main(void)
// {
// 	char	*dst;
// 	char 	*src;
// 	size_t	n;

// 	n = 17;
// 	dst = (char *) malloc (n);
// 	if (!dst)
// 		return (0);
// 	src = "Lalala";
// 	dst = ft_memcpy(dst, src, n);
// 	printf("%s\n", dst);
// 	free (dst);
// }

/*
* Test 2 - String overlap: Source > Destination
*/

// int	main(void)
// {
// 	char	str1[] = "0123456789Lalala";
// 	char	str2[] = "0123456789Lalala";
// 	size_t	n;

// 	n = 12;
// 	printf("%s\n", (char *)ft_memcpy(str1, str1+5, n));
// 	printf("%s\n", (char *)memcpy(str2, str2+5, n));
// }

/*
* Experiment 3 - String overlap: Source < Destination - Undefined results
*/

// int	main(void)
// {
// 	char	str1[] = "0123456789Lalala";
// 	char	str2[] = "0123456789Lalala";
// 	size_t	n;

// 	n = 12;
// 	printf("%s\n", (char *)ft_memcpy(str1+5, str1, n));
// 	printf("%s\n", (char *)memcpy(str2+5, str2, n));
// }