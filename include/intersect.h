#ifndef INTERSECT_H
# define INTERSECT_H

#include "scene.h"
#include "rays.h"

typedef struct s_intersections t_xs;

typedef struct s_intersections
{
	t_object	*object;
	int			count;
	double		t[2];
	t_xs		*next;
}	t_xs;

typedef struct s_sphere_intersection
{
	int		count;
	double	t[2];
}	t_sphere_xs;

t_xs	*new_intersection_node(void);
t_xs	*intersect(t_ray *ray, t_object *object);
t_xs	*sphere_intersect(t_ray *ray, t_object *sphere);
double	calculate_discriminant(t_ray *ray);

#endif