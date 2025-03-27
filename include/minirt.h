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

# define PIXELS 64
# define MAX_WINDOW_WIDTH 3840
# define MAX_WINDOW_HEIGHT 2160

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			width;
	int			height;
}	t_data;

void	key_hooks(mlx_key_data_t keydata, void *param);

#endif