/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:37:06 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:37:07 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;

	d = (unsigned char *) dest;
	i = 0;
	if (!d && !(unsigned char *) src)
		return (0);
	if ((size_t)dest > (size_t)src
		&& (size_t)((unsigned char *) src + n) >= (size_t)dest)
	{
		while (n > 0)
		{
			*(d + n - 1) = *((unsigned char *)src + n - 1);
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			*(d + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}

/*
* Test 1 - String overlap: Source < Destination
*/

// int	main(void)
// {
// 	char	str1[] = "0123456789Lalala";
// 	char	str2[] = "0123456789Lalala";
// 	size_t	n;

// 	n = 12;
// 	printf("%s\n", (char *)ft_memmove(str1+5, str1, n));
// 	printf("%s\n", (char *)memmove(str2+5, str2, n));
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
// 	printf("%s\n", (char *)ft_memmove(str1, str1+5, n));
// 	printf("%s\n", (char *)memmove(str2, str2+5, n));
// }

/*
* Test 3 - No Overlaping
*/

// int	main(void)
// {
// 	char	str1[] = "0123456789Lalala";
// 	char	str2[] = "Boo Loo Pam!";
// 	char	str3[] = "0123456789Lalala";
// 	char	str4[] = "Boo Loo Pam!";
// 	size_t	n;

// 	n = 12;
// 	printf("%s\n", (char *)ft_memmove(str1, str2, n));
// 	printf("%s\n", (char *)memmove(str3, str4, n));
// }
