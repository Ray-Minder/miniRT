#include "../../include/minirt.h"

t_x	*new_intersection_node(void)
{
	t_x	*new_node;

	new_node = ft_calloc(1, sizeof(t_x));
	if (!new_node)
	{
		perror("Failed to create new intersection node.");
		return (NULL);
	}
	new_node->object = NULL;
	new_node->t = 0;
	new_node->hit = false;
	new_node->next = NULL;
	return (new_node);
}

void	free_intersections_list(t_x **xs_list)
{
	t_x	*current;
	t_x	*next;

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
	*xs_list = NULL;
}

void	free_intersection_node(t_x **node_ptr)
{
	if (!node_ptr || !*node_ptr)
		return ;
	free (*node_ptr);
	*node_ptr = NULL;
	return ;
}

void print_intersection_list(t_x *xs_list)
{
	t_x	*current;

	if (!xs_list)
	{
		printf("Intersection list is NULL.\n");
		return ;
	}
	current = xs_list;
	while (current != NULL)
	{
		printf("t: %f, hit: %d\n", current->t, current->hit);
		current = current->next;
	}
}
