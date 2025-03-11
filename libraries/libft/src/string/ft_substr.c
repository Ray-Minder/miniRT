#include "../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		start = s_len;
		len = 0;
	}
	if (len + start > s_len)
		len = s_len - start;
	str = (char *) malloc (len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}

/*
* Test 1 - empty str
*/

// int	main(void)
// {
// 	char			*str;
// 	unsigned int	start;
// 	size_t			len;
// 	char			*substr;

// 	str = "";
// 	start = 2;
// 	len = ft_strlen(str);
// 	substr = ft_substr(str, start, len);
// 	printf("%s\n", substr);
// 	free (substr);
// }

/*
* Test 2 - start > len
*/

// int	main(void)
// {
// 	char			*str;
// 	unsigned int	start;
// 	size_t			len;
// 	char			*substr;

// 	str = "Blablablablabla";
// 	start = 100;
// 	len = ft_strlen(str);
// 	substr = ft_substr(str, start, len);
// 	printf("%s\n", substr);
// 	free (substr);
// }

/*
* Test 3 - len > start && start == 0
*/

// int	main(void)
// {
// 	char			*str;
// 	unsigned int	start;
// 	size_t			len;
// 	char			*substr;

// 	str = "Blablablablabla";
// 	start = 0;
// 	len = ft_strlen(str);
// 	substr = ft_substr(str, start, len);
// 	printf("%s\n", substr);
// 	free (substr);
// }

/*
* Test 4 - len == 1 && start == 0
*/

// int	main(void)
// {
// 	char			*str;
// 	unsigned int	start;
// 	size_t			len;
// 	char			*substr;

// 	str = "Blablablablabla";
// 	start = 0;
// 	len = 1;
// 	substr = ft_substr(str, start, len);
// 	printf("%s\n", substr);
// 	free (substr);
// }
