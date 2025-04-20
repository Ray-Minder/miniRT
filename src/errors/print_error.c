#include "../../include/minirt.h"

//	=== Function Declarations ===

void	print_clean_and_exit(t_data *data, t_error err_no, int exit_code);
void	print_error_msg(char *error_msg);
void	print_errno(char *function_name);

//	=== Function Definitions ===

void	print_clean_and_exit(t_data *data, t_error err_no, int exit_code)
{
	print_error(err_no);
	clean_and_exit(data, exit_code);
}

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
