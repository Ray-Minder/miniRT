/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:37 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:38 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = 0;
	while (dst[dstlen])
		dstlen++;
	while ((dstlen + i) < (size - 1) && src[i] && size > 0)
	{
		dst[dstlen + i] = (char) src[i];
		i++;
	}
	if ((dstlen + i) > (size) || size == 0)
		return (size + ft_strlen(src));
	else
	{
		dst[dstlen + i] = '\0';
		return (dstlen + ft_strlen(src));
	}
}

/*
* Test 1 - size > dstlen && size < (srclen + '\0')
*/

// int	main(void)
// {
// 	char	str1[10];
// 	char	str2[10];
// 	int		n;

// 	*str1 = '\0';
// 	*str2 = '\0';
// 	n = 4;
// 	printf("%zu\n", strlcat(str1, "aaaa", n));
// 	printf("%s\n", str1);
// 	printf("%zu\n", ft_strlcat(str2, "aaaa", n));
// 	printf("%s\n", str2);
// }

/*
* Test 2 - size < dstlen
*/

// int	main(void)
// {
// 	char	str1[10] = "Blablabla";
// 	char	str2[10] = "Blablabla";
// 	int		n;

// 	n = 10;
// 	printf("%zu\n", strlcat(str1, "aaaa", n));
// 	printf("%s\n", str1);
// 	printf("%zu\n", ft_strlcat(str2, "aaaa", n));
// 	printf("%s\n", str2);
// }

/*
* Test 3 - size > dstlen - Undefined results
*/

// int	main(void)
// {
// 	char	str1[10] = "Blablabla";
// 	char	str2[10] = "Blablabla";
// 	int		n;

// 	n = 20;
// 	printf("%zu\n", strlcat(str1, "aaaa", n));
// 	printf("%s\n", str1);
// 	printf("%zu\n", ft_strlcat(str2, "aaaa", n));
// 	printf("%s\n", str2);

// 	// printf("%zu\n", ft_strlcat(str1, "aaaa", n));
// 	// printf("%s\n", str1);
// 	// printf("%zu\n", strlcat(str2, "aaaa", n));
// 	// printf("%s\n", str2);
// }
