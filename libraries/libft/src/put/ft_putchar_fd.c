/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:26 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:27 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/*
* Test 1
*/

// int	main(void)
// {
// 	int		fd;
// 	char	ch;

// 	fd = 1;
// 	ch = 'L';
// 	ft_putchar_fd(ch, fd);
// 	ft_putchar_fd('\n', fd);
// }
