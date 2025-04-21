#include "../../include/minirt.h"

//	=== Function Declarations ===

void	key_hooks(mlx_key_data_t keydata, void *param);

//	=== Function Definitions ===

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("Closing the window\n");
		mlx_close_window(data->mlx);
	}
}
