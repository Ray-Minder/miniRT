/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:15:11 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:15:12 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*gnl_strdup(char *s);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(const char *s);
size_t	nl_index(char *string);
char	*get_next_line(int fd);
void	*gnl_free(char **string);

#endif