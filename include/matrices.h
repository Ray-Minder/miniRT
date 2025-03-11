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
t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b);
void 		free_matrix(t_matrix **matrix);

t_tuple		multiply_matrix_by_tuple(t_matrix *m, t_tuple t);
t_tuple		get_row_as_tuple(t_matrix *m, int row);
t_matrix	*transpose_matrix(t_matrix *m);
t_matrix	*submatrix(t_matrix	*m, int row, int column);

void 		print_matrix(t_matrix* matrix);


#endif