#include "../../include/transformations.h"

t_matrix	*translation(double x, double y, double z)
{
	t_matrix	*translation_matrix;

	translation_matrix = identity(4);
	if (!is_matrix_initialized(translation_matrix))
	{
		perror("Translation");
		return (NULL);
	}
	translation_matrix->values[0][3] = x;
	translation_matrix->values[1][3] = y;
	translation_matrix->values[2][3] = z;
	return (translation_matrix);
}

t_matrix	*translate_from_tuple(t_tuple tuple)
{
	t_matrix	*translation_matrix;

	translation_matrix = identity(4);
	if (!is_matrix_initialized(translation_matrix))
	{
		perror("Translate from tuple");
		return (NULL);
	}
	translation_matrix->values[0][3] = tuple.x;
	translation_matrix->values[1][3] = tuple.y;
	translation_matrix->values[2][3] = tuple.z;
	return (translation_matrix);
}
