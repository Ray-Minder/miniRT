#ifndef INTERSECT_H
# define INTERSECT_H

#include "scene.h"
#include "rays.h"

typedef struct s_intersect
{
	t_object *object;
	double t;
}	t_intersect;

typedef struct s_sphere_intersection
{
	int count;
	double t[2];
}	t_xs;

t_xs	sphere_intersect(t_ray *ray, t_object *sphere);
double	calculate_discriminant(t_ray *ray);

#endif