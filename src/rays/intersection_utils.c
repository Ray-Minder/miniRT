#include "../../include/intersect.h"

t_xs	*new_intersection_node(void)
{
	t_xs	*new_node;

	new_node = ft_calloc(1, sizeof(t_xs));
	if (!new_node)
	{
		perror("Failed to create new intersection node.");
		return (NULL);
	}
	new_node->next = NULL;
	new_node->object = NULL;
	new_node->count = 0;
	new_node->t[0] = 0;
	new_node->t[1] = 0;
	return (new_node);
}

void	free_intersections_list(t_xs **xs_list)
{
	t_xs	*current;
	t_xs	*next;

	if (!xs_list || !*xs_list)
		return ;
	current = (*xs_list);
	next = (*xs_list)->next;
	while (current != NULL)
	{
		free_intersection_node(&current);
		current = next;
		if (current != NULL)
			next = current->next;
	}
}

void	free_intersection_node(t_xs **node_ptr)
{
	if (!node_ptr || !*node_ptr)
		return ;
	free (*node_ptr);
	*node_ptr = NULL;
	return ;
}
