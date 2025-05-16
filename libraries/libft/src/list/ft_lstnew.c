/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:15 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:16 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *) malloc (sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	(*new_list).content = content;
	new_list->next = NULL;
	return (new_list);
}

/*
* Test 1
*/

// int	main(void)
// {
// 	char	*str;
// 	t_list	*new_list;

// 	str = "Content";
// 	new_list = ft_lstnew(str);
// 	printf("%s\n", (char *)new_list->content);
// 	free(new_list);
// }
