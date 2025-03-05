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
void	print_tuple(t_tuple tuple);

#endif