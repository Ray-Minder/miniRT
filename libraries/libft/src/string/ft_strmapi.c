/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:41 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:42 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *) malloc (ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
* Test 1
*/

// static char	ft_f(unsigned int index, char ch)
// {
// 	char	c;

// 	c = ch + 1;
// 	return (c);
// }

// int	main(void)
// {
// 	char	*str;
// 	char	*str2;
// 	char	(*f_ptr)(unsigned int, char);

// 	str = "Bla";
// 	f_ptr = ft_f;
// 	str2 = ft_strmapi(str, ft_f);
// 	printf("%s\n", str2);
// 	free (str2);
// }
