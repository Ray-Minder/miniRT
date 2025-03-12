#include "../../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (i > j)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[j]))
		j--;
	str = malloc (j - i + 2);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[i], (j - i + 2));
	return (str);
}

/*
* Test 1
*/

// int	main(void)
// {
// 	char	str1[] = " ., lalala la. ,";
// 	char	set[] = " .,";
// 	char	*str;

// 	str = ft_strtrim(str1, set);
// 	printf("%lu\n", ft_strlen(str1));
// 	printf("%s\n", str);
// 	printf("%lu\n", ft_strlen(str));
// 	free (str);
// }

/*
* Test 2
*/

// int	main(void)
// {
// 	char	str1[] = "   .  , l,ala.la 1  ..,,   ,.";
// 	char	set[] = " .,";
// 	char	*str;

// 	str = ft_strtrim(str1, set);
// 	printf("%s\n", str);
// 	free (str);
// }

/*
* Test 3 - All the characters in str are in set -> returns empty string.
*/

// int	main(void)
// {
// 	char	str1[] = "   \n\t \n\n\n\n ";
// 	char	set[] = " \n\t";
// 	char	*str;

// 	str = ft_strtrim(str1, set);
// 	printf("%s\n", str);
// 	free (str);
// }

/*
* Test 4 - Empty set and str -> returns empty string.
*/

// int	main(void)
// {
// 	char	str1[] = "";
// 	char	set[] = "";
// 	char	*str;

// 	str = ft_strtrim(str1, set);
// 	printf("%s\n", str);
// 	free (str);
// }
