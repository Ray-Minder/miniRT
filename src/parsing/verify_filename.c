#include "../../include/parser.h"
#include "../../include/minirt.h"

bool	verify_filename(char *filename)
{
	const char	*extension = ft_strrchr(filename, '.');

	if (!extension || ft_strncmp(extension, ".rt", 4) != 0)
		return (false);
	return (true);
}
