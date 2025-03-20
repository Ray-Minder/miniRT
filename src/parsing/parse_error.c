#include "../../include/parser.h"
#include "../../libft/libft.h"

static char	*g_error_messages[] = {
	"Success",
	"Invalid filename",
	"No access",
	"Invalid element",
	"Split error",
	"Invalid double",
	"Invalid integer",
	"Invalid argument count",
	"Too many ambient lights",
	"No ambient light",
	"Too many cameras",
	"No camera",
	"Too many lights",
	"No light",
	"FOV out of range",
	"Double out of range",
	"Malloc failed"
};

int	print_error(t_error error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(g_error_messages[error], 2);
	ft_putstr_fd("\n", 2);
	return (error);
}
