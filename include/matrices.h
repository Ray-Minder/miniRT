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

#endif#ifndef MATRICES_H
# define MATRICES_H

# include <stdio.h>
# include <math.h>

typedef struct s_matrix
{
	int		rows;
	int		cols;
	double	**values;
}	t_matrix;

t_matrix	create_matrix(int rows, int cols);
void		free_matrix(t_matrix matrix);
void		print_matrix(t_matrix matrix);
void		set_matrix_value(t_matrix *matrix, int row, int col, double value);
double		get_matrix_value(t_matrix matrix, int row, int col);




#endif