#ifndef MATRICES_H
# define MATRICES_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "utilities.h"
# include "constants.h"
# include "tuples.h"
# include "../libraries/libft/include/libft.h"

typedef struct s_matrix {
	int		rows;
	int		columns;
	double	**values;
}	t_matrix;

// matrices.c

t_matrix	*create_matrix(int rows, int columns);
void 		initialize_matrix(t_matrix *matrix, double *data, int data_size);
t_matrix	*identity(int size);
double		get_value(t_matrix *matrix, int row, int col);
void		set_value(t_matrix *matrix, int row, int col, double value);

//	matrix_operations_1.c

bool		compare_matrices(t_matrix *a, t_matrix *b);
t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b);
t_tuple		multiply_matrix_by_tuple(t_matrix *m, t_tuple t);
t_matrix	*transpose_matrix(t_matrix *m);

//	matrix_operations_2.c

t_matrix	*submatrix(t_matrix	*m, int row, int column);
double		determinant(t_matrix *m);
double		cofactor(t_matrix *m, int row, int col);
t_matrix	*invert_matrix(t_matrix *m);

//	matrix_utils.c

void 	free_matrix(t_matrix **matrix);
bool	is_matrix_initialized(t_matrix *matrix);
void 	print_matrix(t_matrix* matrix);
t_tuple	get_row_as_tuple(t_matrix *m, int row);

#endif