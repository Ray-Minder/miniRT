#ifndef MATRICES_H
# define MATRICES_H

# include <stdbool.h>

typedef struct s_matrix {
	int		rows;
	int		colums;
	double	**data;
}	t_matrix;

t_matrix	create_matrix(int rows, int colums, double *data);
bool		compare_matrices(t_matrix m1, t_matrix m2);

#endif