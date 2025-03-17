#include "../../include/transformations.h"

t_matrix	*rotation_x(double radians)
{
	t_matrix	*rotation_matrix;
	double		cosine;
	double		sine;

	rotation_matrix = identity(4);
	if (!is_matrix_initialized(rotation_matrix))
	{
		perror("Rotation_x");
		return (NULL);
	}
	cosine = cos(radians);
	sine = sin(radians);
	rotation_matrix->values[1][1] = cosine;
	rotation_matrix->values[1][2] = -sine;
	rotation_matrix->values[2][1] = sine;
	rotation_matrix->values[2][2] = cosine;
	return (rotation_matrix);
}

t_matrix	*rotation_y(double radians)
{
	t_matrix	*rotation_matrix;
	double		cosine;
	double		sine;

	rotation_matrix = identity(4);
	if (!is_matrix_initialized(rotation_matrix))
	{
		perror("Rotation_y");
		return (NULL);
	}
	cosine = cos(radians);
	sine = sin(radians);
	rotation_matrix->values[0][0] = cosine;
	rotation_matrix->values[0][2] = sine;
	rotation_matrix->values[2][0] = -sine;
	rotation_matrix->values[2][2] = cosine;
	return (rotation_matrix);
}

t_matrix	*rotation_z(double radians)
{
	t_matrix	*rotation_matrix;
	double		cosine;
	double		sine;

	rotation_matrix = identity(4);
	if (!is_matrix_initialized(rotation_matrix))
	{
		perror("Rotation_z");
		return (NULL);
	}
	cosine = cos(radians);
	sine = sin(radians);
	rotation_matrix->values[0][0] = cosine;
	rotation_matrix->values[0][1] = -sine;
	rotation_matrix->values[1][0] = sine;
	rotation_matrix->values[1][1] = cosine;
	return (rotation_matrix);
}
