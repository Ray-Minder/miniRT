#include "../../include/parser.h"
#include <stdbool.h>
#include "../../libraries/libft/include/libft.h"

double	ft_atodbl(char *s)
{
	double	result;
	double	power;
	int		sign;

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

bool	ft_is_double(const char *s)
{
	int	i;
	int	dot;

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

double	ft_safe_atodbl(char *s)
{
	if (!ft_is_double(s))
		return (0);
	return (ft_atodbl(s));
}

int	parse_double(const char *s, double *result)
{
	*result = 0;
	if (!ft_is_double(s))
		return (INVALID_DOUBLE);
	*result = ft_atodbl((char *)s);
	return (SUCCESS);
}

int	parse_tuple(char *line, t_tuple *tuple)
{
	char	**split_line;
	int		error;

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
