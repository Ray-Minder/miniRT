#include "../../include/parser.h"
#include <stdbool.h>
#include "../../libft/libft.h"

/**
 * @brief Converts a string to a double.
 *
 * This function takes a string representation of a number and converts it
 * to a double-precision floating-point number.
 *
 * @param s The string to be converted.
 * @return The converted double value.
 */
double ft_atodbl(char *s)
{
	double result;
	double power;
	int sign;

	result = 0.0;
	power = 0.1;
	sign = 1;
	if (s[0] == '-')
		sign = -sign;
	while (*s && *s != '.')
	{
		if (ft_isdigit(*s))
			result = result * 10 + (*s - '0');
		s++;
	}
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			result = result + (power * (*s - '0'));
			power *= 0.1;
		}
		s++;
	}
	return (result * sign);
}

/**
 * @brief Checks if a given string represents a valid double value.
 *
 * This function verifies if the input string `s` is a valid representation
 * of a double-precision floating-point number. It allows for an optional
 * leading sign ('+' or '-'), a single decimal point, and digits.
 *
 * @param s The input string to be checked.
 * @return true if the string represents a valid double value, false otherwise.
 */
bool ft_is_double(const char *s)
{
	int i;
	int dot;

	i = 0;
	dot = 0;
	if (!s || (s[0] != '-' && s[0] != '.' && s[0] != '+' && !ft_isdigit(s[0])))
		return (false);
	if (s[0] == '+' || s[0] == '-')
		i++;
	if (!s[i])
		return (false);
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (++dot > 1 || !s[i + 1])
				return (false);
		}
		else if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Safely converts a string to a double.
 *
 * This function checks if the given string can be converted to a double
 * using the `ft_is_double` function. If the string is a valid double,
 * it converts the string to a double using the `ft_atodbl` function.
 * If the string is not a valid double, it returns 0.
 *
 * @param s The string to be converted to a double.
 * @return The converted double value if the string is valid, otherwise 0.
 */
double ft_safe_atodbl(char *s)
{
	if (!ft_is_double(s))
		return (0);
	return (ft_atodbl(s));
}

/**
 * @brief Parses a string to a double value.
 *
 * This function checks if the given string represents a valid double value.
 * If the string is valid, it converts the string to a double and stores the
 * result in the provided double pointer.
 *
 * @param s The string to be parsed.
 * @param result A pointer to a double where the parsed value will be stored.
 * @return Returns NO_ERROR if the string is a valid double and the conversion
 *         is successful. Returns INVALID_DOUBLE if the string is not a valid
 *         double.
 */
int	parse_double(const char *s, double *result)
{
	*result = 0;
	if (!ft_is_double(s))
		return (INVALID_DOUBLE);
	*result = ft_atodbl((char *)s);
	return (SUCCESS);
}

int parse_tuple(char *line, t_tuple *tuple)
{
	char **split_line;
	int error;
	
	split_line = ft_split(line, ',');
	if (!split_line)
		return (SPLIT_ERROR);
	if (count_tokens(split_line) != 3)
	{
		ft_free_ptrs(split_line);
		return (INVALID_ARG_COUNT);
	}
	error = parse_double(split_line[0], &tuple->x);
	error += parse_double(split_line[1], &tuple->y);
	error += parse_double(split_line[2], &tuple->z);
	if (error != SUCCESS)
	{
		ft_free_ptrs(split_line);
		return (INVALID_DOUBLE);
	}
	ft_free_ptrs(split_line);
	return (SUCCESS);
}
