#include "../../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long			nbr;
	char			digit;

	if (fd < 0)
		return ;
	nbr = n;
	digit = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr == 0)
		write(fd, "0", 1);
	if (nbr > 0 && nbr < 10)
	{
		digit = nbr + '0';
		write (fd, &digit, 1);
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		digit = (nbr % 10) + '0';
		write (fd, &digit, 1);
	}
}

/*
* Test 1
*/

// int	main(void)
// {
// 	int	n;
// 	int	fd;

// 	n = -2147483648;
// 	fd = 1;
// 	ft_putnbr_fd(n, fd);
// }

/*
* Test 2
*/

// int	main(void)
// {
// 	int	n;
// 	int	fd;

// 	n = 10;
// 	fd = 1;
// 	ft_putnbr_fd(n, fd);
// }

/*
* Test 3
*/

// int	main(void)
// {
// 	int	n;
// 	int	fd;

// 	n = 55510;
// 	fd = 1;
// 	ft_putnbr_fd(n, fd);
// }
