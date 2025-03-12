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
