#ifndef TUPLES_H
# define TUPLES_H

# include <stdio.h>
# include <math.h>

# define EPSILON 0.00001

typedef struct s_tuple {
    double x;
    double y;
    double z;
    double w;
}	t_tuple;

t_tuple	tuple(double x, double y, double z, double w);
void	print_tuple(t_tuple tuple);

t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);

t_tuple add_tuples(t_tuple a, t_tuple b);
t_tuple	subtract_tuples(t_tuple a, t_tuple b);
t_tuple	negate_tuple(t_tuple t);

t_tuple	multiply_tuple_by_scalar(t_tuple t, double scalar);
t_tuple	divide_tuple_by_scalar(t_tuple t, double scalar);
double  tuple_magnitude(t_tuple t);
t_tuple normalize_tuple(t_tuple t);
double    dot_product(t_tuple a, t_tuple b);
t_tuple cross_product(t_tuple a, t_tuple b);




#endif