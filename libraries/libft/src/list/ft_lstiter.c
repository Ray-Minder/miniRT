/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:11 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:12 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current_ptr;
	t_list	*next_ptr;

	if (lst == NULL)
		return ;
	current_ptr = lst;
	next_ptr = lst->next;
	while (current_ptr != NULL)
	{
		next_ptr = current_ptr->next;
		f(current_ptr->content);
		current_ptr = next_ptr;
	}
}

/*
*	Test 1
*/

// static void	ft_del(void *content)
// {
// 	content = NULL;
// }

// static void	ft_f(void *content)
// {
// 	printf("%s\n", (char *) content);
// }

// int	main(void)
// {
// 	t_list	*lst1;
// 	t_list	*lst2;

// 	lst1 = (t_list *)malloc (sizeof(t_list));
// 	lst2 = (t_list *)malloc (sizeof(t_list));
// 	lst1->content = "This is Content1";
// 	lst2->content = "This is Content2";
// 	lst1->next = lst2;
// 	lst2->next = NULL;
// 	ft_lstiter(lst1, ft_f);
// 	ft_lstclear(&lst1, ft_del);
// }
