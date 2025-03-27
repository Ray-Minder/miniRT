#ifndef COLORS_H
# define COLORS_H

# include <stdio.h>
# include <math.h>

# include "tuples.h"
# include "scene.h"

t_color	color(uint8_t r, uint8_t g, uint8_t b);
t_color	add_colors(t_color c1, t_color c2);
t_color	subtract_colors(t_color c1, t_color c2);
t_color	multiply_color_by_scalar(t_color c, double scalar);
t_color	divide_color_by_scalar(t_color c, double scalar);
t_color	hadamard_product(t_color c1, t_color c2);

// t_tuple	color(double r, double g, double b);
// t_tuple	add_colors(t_tuple c1, t_tuple c2);
// t_tuple	subtract_colors(t_tuple c1, t_tuple c2);
// t_tuple	multiply_color_by_scalar(t_tuple c, double scalar);
// t_tuple	divide_color_by_scalar(t_tuple c, double scalar);
// t_tuple	hadamard_product(t_tuple c1, t_tuple c2);

#endif