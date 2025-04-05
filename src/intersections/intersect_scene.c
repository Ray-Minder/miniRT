#include "../../include/minirt.h"

t_x	*intersect_scene(t_ray *ray, t_scene *scene)
{
	t_object	*current;
	t_x			*head;
	t_x			*last_node;
	t_x			*obj_intersections; //Intersections for current object

	current = scene->objects;
	head = NULL;
	last_node = NULL;
	while (current != NULL)
	{
		if (current->type == SPHERE) {
			obj_intersections = sphere_intersect(ray, current);
		} else if (current->type == PLANE) {
			obj_intersections = plane_intersect(ray, current);
		} else if (current->type == CYLINDER) {
			obj_intersections = cylinder_intersect(ray, current);
		} else {
			// Should not happen with valid parsing, but good to handle
			obj_intersections = NULL;
		}
	// --- Append the found intersections (if any) to the main list ---
	if (obj_intersections != NULL)
	{
		if (head == NULL)
		{
			// If this is the first intersection(s) found
			head = obj_intersections;
			// Find the new last node (obj_intersections might be a list itself)
			last_node = head;
			while (last_node != NULL && last_node->next != NULL) {
				 last_node = last_node->next;
			}
		}
		else
		{
			// Append the new list to the end of the existing list
			// 'last_node_in_all' should point to the last node added previously
			if (last_node != NULL)
			{ // Safety check
				last_node->next = obj_intersections;
				// Update last_node_in_all to the end of the newly added list
				while (last_node->next != NULL) {
					last_node = last_node->next;
				}
			}
			else
			{
				// Should not happen if logic is correct, but handle defensively
				// This might occur if the list became empty unexpectedly
				fprintf(stderr, "Warning: last_node_in_all was NULL during append.\n");
				head = obj_intersections; // Reset list head
				 last_node = head;
				 while (last_node != NULL && last_node->next != NULL)
					 last_node = last_node->next;
			}
		}
	}
	// Move to the next object in the scene
	current = current->next;
	}
	// The list is now complete (or NULL if nothing was hit)
	return (head);
}
