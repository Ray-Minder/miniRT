/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:37:00 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:37:01 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc (0);
		return (ptr);
	}
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

/*
* Test 1
*/

// int	main(void)
// {
// 	char	*str;
// 	size_t	len;

// 	len = 50;
// 	str = (char *) ft_calloc (50, len);
// 	if (str == NULL)
// 	{
// 		printf("NULL\n");
// 		return (0);
// 	}
// 	strcpy(str, "lalal");
// 	printf("%s\n", str);
// 	free (str);
// }

/*
* Test 2 - Tests if len and nmemb 0 still creates a pointer that can be freed.
*/

// int	main(void)
// {
// 	char	*str;

// 	str = (char *) ft_calloc (0, 0);
// 	if (str == NULL)
// 	{
// 		printf("NULL\n");
// 		return (0);
// 	}
// 	free (str);
// }

/*
* Test 3 - Tests if the string contains null characters
*	If it doesn't it should print Null.
*	If it only does at the end it should print c in the first attempt.
*	We search for c afterwards to check if that works too.
*/

// int	main(void)
// {
// 	char	*str;
// 	size_t	len;

// 	len = 3;
// 	str = (char *) ft_calloc (50, len);
// 	if (str == NULL)
// 	{
// 		printf("NULL\n");
// 		return (0);
// 	}
// 	str[148] = 'c';
// 	printf("%s\n", (char *) ft_memchr(str, '\0', 150));
// 	printf("%s\n", (char *) ft_memchr(str, 'c', 150));
// 	free (str);
// }
