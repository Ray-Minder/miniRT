/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:35:59 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:00 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	long long	nbr;
	int			is_negative;

	i = 0;
	nbr = 0;
	is_negative = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_negative = 1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	if (is_negative)
		return ((int) -nbr);
	return (nbr);
}

/*
* Test 1 - Min int
*/

// int	main(void)
// {
// 	char	str[] = "   \f-2147483648dgdfgf";
// 	size_t	len;

// 	len = -1;
// 	printf("%d\n", atoi(str));
// 	printf("%d\n", ft_atoi(str));
// }

/*
* Test 2 - Int overflow
*/

// int	main(void)
// {
// 	char	str[] = "   \f-214748581813648dgdfgf";
// 	size_t	len;

// 	len = -1;
// 	printf("%d\n", atoi(str));
// 	printf("%d\n", ft_atoi(str));
// }

/*
* Test 3 - Multiple minuses and pluses
*/

// int	main(void)
// {
// 	char	str[] = "   \f+-++--214743648dgdfgf";
// 	size_t	len;

// 	len = -1;
// 	printf("%d\n", atoi(str));
// 	printf("%d\n", ft_atoi(str));
// }
