#ifndef NORMALS_H
# define NORMALS_H

# include "tuples.h"
# include "scene.h"

t_tuple	normal_at_sphere(t_object *object, t_tuple point);
t_tuple reflect(t_tuple in, t_tuple normal);

#endif