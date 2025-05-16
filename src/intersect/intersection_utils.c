/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersection_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:12:01 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:12:02 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

t_x		*new_intersection_node(void);
void	add_intersection_node(t_x **xs_list, t_x *current);
void	free_intersections_list(t_x **xs_list);
void	free_intersection_node(t_x **node_ptr);
void	print_intersection_list(t_x *xs_list);

//	=== Function Definitions ===

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
	new_node->is_hit = false;
	new_node->next = NULL;
	return (new_node);
}

/**
 * @brief Adds an intersection node to the end of the linked list.
 * 
 * @param xs_list Pointer to the head of the linked list of intersection points
 * @param current Pointer to the current intersection point to be added.
 * 
 * This function traverses the linked list
 * and adds the current intersection point to the end of the list.
 * If the list is empty, it sets the head to the current point.
 */
void	add_intersection_node(t_x **xs_list, t_x *current)
{
	t_x	*iterator;

	if (!xs_list && !current)
	{
		ft_putstr_fd("Error: xs_list and current are NULL.\n", 2);
		return ;
	}
	if (xs_list && !*xs_list && current)
	{
		*xs_list = current;
		return ;
	}
	iterator = *xs_list;
	while (iterator && iterator->next)
		iterator = iterator->next;
	iterator->next = current;
}

void	free_intersections_list(t_x **xs_list)
{
	t_x	*current;
	t_x	*next;

	if (!xs_list || !*xs_list)
		return ;
	current = (*xs_list);
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
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

void	print_intersection_list(t_x *xs_list)
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
		printf("t: %f, hit: %d\n", current->t, current->is_hit);
		current = current->next;
	}
	printf("\n");
}
