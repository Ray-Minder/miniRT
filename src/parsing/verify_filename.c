#include "../../include/minirt.h"

//	=== Function Declarations ===

bool	verify_filename(char *filename);

//	=== Function Definitions ===

bool	verify_filename(char *filename)
{
	const char	*extension = ft_strrchr(filename, '.');

	if (!extension || ft_strncmp(extension, ".rt", 4) != 0)
		return (false);
	return (true);
}
