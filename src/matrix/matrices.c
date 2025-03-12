#include "../../include/matrices.h"

//	=== Function Declarations ===

t_matrix	*create_matrix(int rows, int columns);
void 		initialize_matrix(t_matrix *matrix, double *data, int data_size);
t_matrix	*identity(int size);
double		get_value(t_matrix *matrix, int row, int col);
void		set_value(t_matrix *matrix, int row, int col, double value);

//	=== Function Definitions ===

t_matrix	*create_matrix(int rows, int columns)
{
	t_matrix	*matrix;
	int			i;

	matrix = malloc(sizeof(t_matrix));
	if (!matrix)
	{
		perror("Failed to allocate memory for matrix");
		return (NULL);
	}
	matrix->rows = rows;
	matrix->columns = columns;
	matrix->values = ft_calloc(rows, sizeof(double *));
	if (!matrix->values)
	{
		free(matrix);
		perror("Failed to allocate memory for matrix rows");
		return (NULL);
	}
	i = -1;
	while (++i < matrix->rows)
	{
		matrix->values[i] = ft_calloc(columns, sizeof(double));
		if (!matrix->values[i])
		{
			while (--i >= 0)
            	free(matrix->values[i]);
			free(matrix->values);
			free(matrix);
			perror("Failed to allocate memory for matrix columns");
			return (NULL);
		}
	}
	return (matrix);
}

void initialize_matrix(t_matrix *matrix, double *data, int data_size)
{
	int	i;
	int	j;
	int	index;

	if (!matrix || !matrix->values || !data)
		return ;
	i = -1;
	while (++i < matrix->rows)
	{
		j = -1;
		while (++j < matrix->columns)
		{
			index = i * matrix->columns + j;
			if (index < data_size)
				matrix->values[i][j] = data[index];
			else
				matrix->values[i][j] = 0;
		}
	}
}

t_matrix	*identity(int size)
{
	t_matrix	*_identity;
	int			r;
	int			c;

	_identity = create_matrix(size, size);
	if (!_identity)
	{
		perror("Identity");
		return (NULL);
	}
	r = -1;
	while (++r < size)
	{
		c = -1;
		while (++c < size)
		{
			if (r == c)
				_identity->values[r][c] = 1.0;
			else
				_identity->values[r][c] = 0.0;
		}
	}
	return (_identity);
}

double	get_value(t_matrix *matrix, int row, int col)
{
	if (!is_matrix_initialized(matrix))
	{
		printf("Impossible to get the value of an uninitialized matrix\n");
		return (0.0);
	}
	if (row > matrix->rows || col > matrix->columns)
	{
		printf("Out of bounds to get the value.\n");
		return (0.0);
	}
	return (matrix->values[row][col]);
}

void	set_value(t_matrix *matrix, int row, int col, double value)
{
	if (!is_matrix_initialized(matrix))
	{
		printf("Impossible to set the value of an uninitialized matrix\n");
		return ;
	}
	if (row > matrix->rows || col > matrix->columns)
	{
		printf("Out of bounds to set the value.\n");
		return ;
	}
	matrix->values[row][col] = value;
}
