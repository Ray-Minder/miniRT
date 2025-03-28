#include <stdint.h>
#include "../../include/parser.h"
#include "../../libraries/libft/include/libft.h"

int	parse_uint8(const char *s, uint8_t *result)
{
	int	i;
	int	res;

	i = 0;
	*result = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) || i > 3)
			return (INVALID_INT);
		i++;
	}
	res = ft_atoi(s);
	if (res > 255)
		return (INVALID_INT);
	*result = (uint8_t)res;
	return (SUCCESS);
}

int	parse_color(char *line, t_color *color)
{
	char	**split_line;
	int		error;
	t_uint8color	color8;

	split_line = ft_split(line, ',');
	if (!split_line)
		return (SPLIT_ERROR);
	if (count_tokens(split_line) != 3)
	{
		ft_free_ptrs(split_line);
		return (INVALID_ARG_COUNT);
	}
	error = parse_uint8(split_line[0], &color8.r);
	error += parse_uint8(split_line[1], &color8.g);
	error += parse_uint8(split_line[2], &color8.b);
	if (error != SUCCESS)
	{
		ft_free_ptrs(split_line);
		return (INVALID_INT);
	}
	color->r = (double)color8.r / 255.0;
	color->g = (double)color8.g / 255.0;
	color->b = (double)color8.b / 255.0;
	ft_free_ptrs(split_line);
	return (SUCCESS);
}
