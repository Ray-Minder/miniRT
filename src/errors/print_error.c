#include "../../include/minirt.h"

void	print_error_msg(char *error_msg)
{
	printf("Error\n");
	printf("%s\n", error_msg);
}

void	print_errno(char *function_name)
{
	printf("Error\n");
	printf("In function %s: %s\n", function_name, strerror(errno));
}
