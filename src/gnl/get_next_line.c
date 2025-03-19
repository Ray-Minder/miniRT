/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 16:47:24 by eandela       #+#    #+#                 */
/*   Updated: 2025/03/19 20:39:28 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	*gnl_free(char **string)
{
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
	return (NULL);
}

char	*read_full_string(int fd, char **remainder)
{
	char	*buffer;
	int		read_size;
	char	*tmp;

	read_size = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!nl_index(*remainder) && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_size] = '\0';
		tmp = gnl_strjoin(*remainder, buffer);
		if (!tmp)
			return (free(buffer), gnl_free(remainder), NULL);
		gnl_free(remainder);
		*remainder = tmp;
	}
	free(buffer);
	return (*remainder);
}

char	*extract_remainder(char *string)
{
	char	*remainder;
	int		i;

	i = 0;
	if (!string)
		return (NULL);
	if (string[0] == '\0')
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] != '\0')
		i++;
	remainder = gnl_strdup(&string[i]);
	if (!remainder)
		return (NULL);
	return (remainder);
}

char	*extract_line(char *string)
{
	char	*line;
	int		i;
	int		index;

	i = 0;
	index = (int)nl_index(string);
	if (!string)
		return (NULL);
	if (index == 0 && string[i] != '\n')
		index = gnl_strlen(string) - 1;
	line = malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	while (i < index + 1)
	{
		line[i] = string[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*full_string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_string = read_full_string(fd, &remainder);
	if (!full_string)
	{
		gnl_free(&remainder);
		return (NULL);
	}
	remainder = extract_remainder(full_string);
	line = extract_line(full_string);
	if (!line)
	{
		gnl_free(&remainder);
		free(full_string);
		return (NULL);
	}
	gnl_free(&full_string);
	if (line[0] == '\0')
		return (free(line), gnl_free(&remainder));
	return (line);
}
