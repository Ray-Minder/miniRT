/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_uint8.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:13:44 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:13:45 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

int	parse_uint8(const char *s, uint8_t *result);
int	parse_color(char *line, t_color *color);

//	=== Function Definitions ===

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
	char			**split_line;
	int				error;
	t_uint8color	uint8color;

	split_line = ft_split(line, ',');
	if (!split_line)
		return (SPLIT_ERROR);
	if (count_tokens(split_line) != 3)
	{
		ft_free_ptrs(split_line);
		return (INVALID_ARG_COUNT);
	}
	error = parse_uint8(split_line[0], &uint8color.r);
	error += parse_uint8(split_line[1], &uint8color.g);
	error += parse_uint8(split_line[2], &uint8color.b);
	if (error != SUCCESS)
	{
		ft_free_ptrs(split_line);
		return (INVALID_INT);
	}
	color->r = (double)uint8color.r / 255.0;
	color->g = (double)uint8color.g / 255.0;
	color->b = (double)uint8color.b / 255.0;
	ft_free_ptrs(split_line);
	return (SUCCESS);
}
