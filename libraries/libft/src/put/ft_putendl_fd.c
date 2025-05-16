/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:29 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:30 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/*
* Test 1
*/

// int	main(void)
// {
// 	char	*str;
// 	int		fd;

// 	str = NULL;
// 	fd = 1;
// 	ft_putendl_fd(str, fd);
// 	return (0);
// }
