#include "../../include/libft.h"

void	ft_putstr_fd(char *s, int fd)
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
}

/*
* Test 1
*/

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = 2;
// 	str = "Lalala";
// 	ft_putstr_fd(str, fd);
// 	ft_putstr_fd("\n", fd);
// }
