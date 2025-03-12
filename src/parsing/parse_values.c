#include <stdbool.h>
#include "../../libft/libft.h"

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
bool ft_is_double(char *s)
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
