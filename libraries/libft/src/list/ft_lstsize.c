/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:36:16 by lprieri       #+#    #+#                 */
/*   Updated: 2025/04/30 12:36:17 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/*
* Test 1
*/

// int	main(void)
// {
// 	t_list	lst1;
// 	t_list	lst2;
// 	t_list	lst3;
// 	int		lst_size;

// 	(&lst1)->content = (char *)"First element";
// 	(&lst1)->next = &lst2;
// 	(&lst2)->content = (char *)"Second element";
// 	(&lst2)->next = &lst3;
// 	(&lst3)->content = (char *)"Third element";
// 	(&lst3)->next = NULL;
// 	lst_size = ft_lstsize(&lst1);
// 	printf("%d\n", lst_size);
// }

/*
* Test 2
*/

// int	main(void)
// {
// 	t_list	*lst1;
// 	int		lst_size;

// 	lst1 = NULL;
// 	lst_size = ft_lstsize(lst1);
// 	printf("%d\n", lst_size);
// }
