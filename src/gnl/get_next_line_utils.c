/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/20 13:03:07 by eandela       #+#    #+#                 */
/*   Updated: 2025/03/19 20:39:28 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

size_t	nl_index(char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*gnl_strdup(char *s)
{
	char	*ptr;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	size = gnl_strlen(s);
	i = 0;
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	if (i == 0)
		return (gnl_free(&ptr), NULL);
	return (ptr);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char			*s3;
	size_t			i;
	const size_t	s1_len = gnl_strlen(s1);
	const size_t	s2_len = gnl_strlen(s2);

	i = 0;
	s3 = malloc(s1_len + s2_len + 1);
	if (!s3)
		return (NULL);
	while (i < s1_len)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		s3[i] = s2[i - s1_len];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
