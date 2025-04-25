#include "../../include/minirt.h"

//	=== Function Declarations ===

int	print_error(t_error error);

//	=== Function Definitions ===


int	print_error(t_error error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *) get_error_msg(error), 2);
	ft_putstr_fd("\n", 2);
	return (error);
}
