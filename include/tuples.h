#ifndef TUPLES_H
# define TUPLES_H

#include <stdio.h>

typedef struct s_tuple {
    double x;
    double y;
    double z;
    double w;
}	t_tuple;

t_tuple	tuple(double x, double y, double z, double w);
t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);
void	print_tuple(t_tuple tuple);

#endif