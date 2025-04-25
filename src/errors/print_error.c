#include "../../include/minirt.h"

//	=== Function Declarations ===

void		print_clean_and_exit(t_data *data, t_error err_no, int exit_code);
const char	*get_error_msg(t_error err_no);
void		print_error_msg(char *error_msg);
void		print_errno(char *function_name);

//	=== Function Definitions ===

void	print_clean_and_exit(t_data *data, t_error err_no, int exit_code)
{
	print_error(err_no);
	clean_and_exit(data, exit_code);
}

const char	*get_error_msg(t_error err_no)
{
	char	*error_msg[ERROR_COUNT];

	error_msg[SUCCESS] = "Success!";
	error_msg[INVALID_FILENAME] = "Invalid filename";
	error_msg[NO_ACCESS] = "No access";
	error_msg[INVALID_ELEMENT] = "Invalid element";
	error_msg[SPLIT_ERROR] = "Split error";
	error_msg[INVALID_DOUBLE] = "Invalid double";
	error_msg[INVALID_INT] = "Invalid int";
	error_msg[INVALID_ARG_COUNT] = "Invalid argument count";
	error_msg[TOO_MANY_AMBIENT_LIGHTS] = "Too many ambient lights";
	error_msg[NO_AMBIENT_LIGHT] = "No ambient light";
	error_msg[TOO_MANY_CAMERAS] = "Too many cameras";
	error_msg[NO_CAMERA] = "No camera";
	error_msg[TOO_MANY_LIGHTS] = "Too many lights";
	error_msg[FOV_OUT_OF_RANGE] = "FOV out of range";
	error_msg[DOUBLE_OUT_OF_RANGE] = "Double out of range";
	error_msg[MALLOC_FAIL] = "Malloc failed";
	error_msg[INVALID_DIRECTION_VECTOR] = "Invalid direction vector";
	if (err_no >= 0 && err_no < ERROR_COUNT)
		return (error_msg[err_no]);
	return (NULL);
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
