#ifndef INTERSECT_H
# define INTERSECT_H

#include "scene.h"
#include "rays.h"

typedef struct s_intersection t_x;
typedef struct s_ray t_ray;

typedef struct s_intersection
{
	t_object	*object;
	double		t;
	bool		hit;
	t_x			*next;
}	t_x;

// typedef struct s_sphere_intersection
// {
// 	int		count;
// 	double	t[2];
// }	t_sphere_xs;

t_x		*intersect(t_ray *ray, t_object *object);
t_x		*hit(t_x *xs_list);
void	add_intersection_node(t_x **xs_list, t_x *current);
t_x		*sphere_intersect(t_ray *ray, t_object *sphere);
double	calculate_discriminant(t_ray *ray);

//	INTERSECTION_UTILS

t_x		*new_intersection_node(void);
void	free_intersections_list(t_x **xs_list);
void	free_intersection_node(t_x **node_ptr);

// TRANSFORM

t_ray	transform(t_ray *ray, t_matrix *matrix);
void	set_transform(t_object *object, t_matrix *transformation);

#endif