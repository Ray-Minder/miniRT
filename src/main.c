#include "../include/minirt.h"

int	main(void)
{
	t_data	data;

	init_data(&data);

	
	render_sphere(&data);
	if (mlx_image_to_window(data.mlx, data.canvas, 0, 0) < 0)
	{
		printf("Failure to put image to window\n");
		return (1);
	}
	
	mlx_key_hook(data.mlx, &key_hooks, (void *) &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);

	printf("Exiting\n");
	return (0);
}
