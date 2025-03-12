#include "../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	ret_value;
	char	*src_ptr;

	ret_value = ft_strlen(src);
	src_ptr = (char *)src;
	if (size == 0)
		return (ret_value);
	while (*src_ptr && (size - 1) > 0)
	{
		*dst = *src_ptr;
		dst++;
		src_ptr++;
		size--;
	}
	*dst = '\0';
	return (ret_value);
}

/*
* Test 1
*/

// int	main(void)
// {
// 	char	str1[10];
// 	char	str2[10];
// 	int		n;

// 	*str1 = '\0';
// 	*str2 = '\0';
// 	n = 4;
// 	printf("%zu\n", strlcpy(str1, "aaaa", n));
// 	printf("%s\n", str1);
// 	printf("%zu\n", ft_strlcpy(str2, "aaaa", n));
// 	printf("%s\n", str2);
// }

/*
* Test 2
*/

// int	main(void)
// {
// 	char	str1[10] = "Blablabla";
// 	char	str2[10] = "Blablabla";
// 	int		n;

// 	n = 10;
// 	printf("%zu\n", strlcpy(str1, "aaaa", n));
// 	printf("%s\n", str1);
// 	printf("%zu\n", ft_strlcpy(str2, "aaaa", n));
// 	printf("%s\n", str2);
// }