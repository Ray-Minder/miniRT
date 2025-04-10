#include "../../include/minirt.h"

/**
 * @brief Prints an error message to the standard output.
 * 
 * @param error_msg The error message to print.
 * @return void
 * @note This function prints "Error" followed by the error message.
 */
void	print_error_msg(char *error_msg)
{
	printf("Error\n");
	printf("%s\n", error_msg);
}

/**
 * @brief Prints an errno's error message to the standard output.
 * 
 * @param function_name The name of the function where the error occurred.
 * @return void
 * @note This function prints "Error"
 * 		followed by the function name and the error message.
 */
void	print_errno(char *function_name)
{
	printf("Error\n");
	printf("In function %s: %s\n", function_name, strerror(errno));
}
