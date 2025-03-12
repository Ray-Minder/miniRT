#ifndef COLORS_H
# define COLORS_H

# include <stdio.h>
# include <math.h>

# include "tuples.h"

t_tuple	color(double r, double g, double b);
t_tuple	add_colors(t_tuple c1, t_tuple c2);
t_tuple	subtract_colors(t_tuple c1, t_tuple c2);
t_tuple	multiply_color_by_scalar(t_tuple c, double scalar);
t_tuple	divide_color_by_scalar(t_tuple c, double scalar);
t_tuple	hadamard_product(t_tuple c1, t_tuple c2);

#endif