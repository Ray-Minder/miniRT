#ifndef TRANSFORMATIONS_H
# define TRANSFORMATIONS_H

# include "matrices.h"
# include "tuples.h"

t_matrix	*translation(double x, double y, double z);
t_matrix	*translate_from_tuple(t_tuple tuple);

t_matrix	*scaling(double x, double y, double z);
t_matrix	*scaling_from_tuple(t_tuple tuple);

t_matrix	*rotation_x(double radians);
t_matrix	*rotation_y(double radians);
t_matrix	*rotation_z(double radians);

t_matrix	*shearing(double xy, double xz, double yx, 
						double yz, double zx, double zy);

t_matrix	*chain_transformations(t_matrix *matrices[]);

#endif