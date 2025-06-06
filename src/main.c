/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:14:32 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:14:33 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

//	=== Function Declarations ===

static void	call_mlx_functions(t_data *data);

//	=== Function Definitions ===

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		printf("Error\nUsage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	init_data(&data);
	parse_scene(&data, argv[1]);
	set_up_camera(&data);
	render_scene(&data);
	call_mlx_functions(&data);
	clean_and_exit(&data, EXIT_SUCCESS);
}

static void	call_mlx_functions(t_data *data)
{
	mlx_key_hook(data->mlx, &key_hooks, (void *) data);
	mlx_loop(data->mlx);
}
