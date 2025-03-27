#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>
# include <assert.h>

# include "../libraries/libft/include/libft.h"
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "colors.h"
# include "constants.h"
# include "matrices.h"
# include "tuples.h"
# include "utilities.h"
# include "transformations.h"
# include "rays.h"
# include "intersect.h"
# include "parser.h"

# define SCALE 4
# define MAX_WINDOW_WIDTH 3840
# define MAX_WINDOW_HEIGHT 2160
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MIN_WINDOW_WIDTH 100
# define MIN_WINDOW_HEIGHT 100

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	t_camera	*cam;
	t_light		*light;
	int			width;
	int			height;
}	t_data;

void	init_data(t_data *data);
void	init_mlx(t_data	*data);
void	key_hooks(mlx_key_data_t keydata, void *param);
void 	render_sphere(t_data *data);

#endif