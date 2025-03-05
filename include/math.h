#ifndef MATH_H
# define MATH_H

// ----- Libraries -----
# include <math.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>

// ----- Colours -----
# define BLACK "\033[30;1m"
# define WHITE "\033[37;1m"
# define RED "\033[31;1m"
# define BLUE "\033[34;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define RESET "\033[0m"

// ----- Math -----
# define M_PI 3.14159265358979323846
# define EPSILON 0.0001
# define DBL_MAX 1.79769e+308

// ----- Structs ------

typedef struct s_tuple
{
	double x;
	double y;
	double z;
	double w;
} t_tuple;


#endif