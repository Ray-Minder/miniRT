#include "../../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		del((lst->content));
		free(lst);
	}
}

/*
* Test 1
*/

/*
* If I use free in this function I get a free(): invalid pointer error.
* Therefore I simply set the content to NULL, to have it do something.
*/

// static void	ft_del(void *content)
// {
// 	content = NULL;
// }

// int	main(void)
// {
// 	t_list	*lst1;
// 	t_list	lst2;

// 	lst1 = (t_list *) malloc (sizeof(t_list));
// 	lst1->content = (char *)"Content";
// 	lst1->next = &lst2;
// 	(&lst2)->content = (char *)"Content2";
// 	(&lst2)->next = NULL;
// 	ft_lstdelone(lst1, ft_del);
// 	printf("%s\n", (char *)(lst2)->content);
// }
