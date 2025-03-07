#ifndef MATRICES_H
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



#endif