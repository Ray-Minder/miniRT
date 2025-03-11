#ifndef MATRICES_H
# define MATRICES_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include "minirt.h"
# include "utilities.h"
# include "constants.h"
# include "tuples.h"

typedef struct s_matrix {
	int		rows;
	int		columns;
	double	**values;
}	t_matrix;

t_matrix	*create_matrix(int rows, int columns);
bool		compare_matrices(t_matrix *a, t_matrix *b);
void		initialize_matrix(t_matrix *matrix, double *data, int data_size);


#endif